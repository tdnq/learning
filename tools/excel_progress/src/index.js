const xlsx = require('node-xlsx');
const path = require('path');
const fs = require('fs-extra');

const dataDir = './data';
const date = new Date();
const dateData = [
    date.getFullYear(),
    date.getMonth() + 1,
    date.getDate()
]
async function getAllData(dir = []) {
    console.log('正在读取excel数据....');
    let data = {};
    dir.forEach(item => {
        let itemData = xlsx.parse(fs.readFileSync(path.join(__dirname, dataDir, item)));
        data[item] = itemData;
    });
    return data;
}
async function getExtractData(sourceData, dataFileName, unitPriceData) {
    console.log('正在提取日耗表数据....')
    let data = {};
    dataFileName.forEach(item => {
        let itemSource = sourceData[item].find(item => item.name === '日耗表') //日料表数据;
        if (!itemSource) {
            if (!item.startsWith('.~')) {
                console.log(['这个表没有日耗表', item].join('--'));
            }
            return;
        }
        let department = itemSource.data[1][0] === '部门' ? itemSource.data[1][1] : null; //部门
        let codeIndex = itemSource.data[2].indexOf('存货编码');
        let currentDayHappenCountIndex = itemSource.data[2].indexOf(`${dateData[2]}日`);
        if (codeIndex === -1) {
            console.log(['没有编码', item].join('--'));
            return;
        }
        if (currentDayHappenCountIndex === -1) {
            let temp = itemSource.data[0].indexOf(`${dateData[2]}`);
            if (temp === -1) {
                console.log(['没有当日发生数', item].join('--'));
                return;
            } else {
                currentDayHappenCountIndex = temp;
                console.log(['当日发生数名称栏不规范', item].join('--'));
            }
        }
        {
            data[item] = { data: [], name: `${department}_日耗表` }
            let startIndex = 3;
            for (let i = startIndex; i < itemSource.data.length; i++) {
                if (!itemSource.data[i] || !itemSource.data[i].length || !(itemSource.data[i][1] || itemSource.data[i][2])) {
                    continue;
                }
                let rowData = null;
                if (department === '酒吧部') {
                    rowData = [
                        ...dateData, //'年', '月', '日'
                        department, // 部门
                        itemSource.data[i][1], //大类
                        itemSource.data[i][3], //存货名称
                        itemSource.data[i][5], //存货编码
                        '', //名称
                        '', //规格
                        '', //计量单位
                        parseInt(itemSource.data[i][currentDayHappenCountIndex]), //当日发生数
                        unitPriceData[itemSource.data[i][codeIndex]] //单价
                    ];
                } else {
                    rowData = [
                        ...dateData, //'年', '月', '日'
                        department, // 部门
                        itemSource.data[i][1], //大类
                        itemSource.data[i][2], //存货名称
                        itemSource.data[i][4], //存货编码
                        '', //名称
                        '', //规格
                        '', //计量单位
                        parseInt(itemSource.data[i][currentDayHappenCountIndex]), //当日发生数
                        unitPriceData[itemSource.data[i][codeIndex]] //单价
                    ];
                }
                let countIndex = 10;
                if (isNaN(rowData[countIndex])) {
                    rowData[countIndex] = 0;
                }
                data[item].data.push(rowData);
            }
        }
    });
    return data;
}
async function buildExcel(extractData) {
    let buildData = []
    Object.keys(extractData).map(key => {
        extractData[key].data.unshift(['年', '月', '日', '部门', '大类', '存货名称', '存货编码', '名称', '规格', '计量单位', '当日发生数', '单价'])
        return buildData.push(extractData[key]);
    });
    // const sheetOptions = { '!cols': [{ wch: 6 }, { wch: 7 }, { wch: 10 }, { wch: 20 }] };

    let buffer = xlsx.build(buildData, {}); // Returns a buffer
    fs.writeFileSync(path.join(__dirname, `./build/${dateData.join('_')}_各部门日耗表.xlsx`), buffer);
    console.log('-----生成日耗表成功!!');
}
async function getUnitPriceData(sourceData, dataFileName) {
    console.log('正在提取单价数据....')
    let data = {};
    dataFileName.forEach(item => {
        let itemSource = sourceData[item].find(item => item.name === '物料单价表') //日料表数据;
        if (itemSource) {
            console.log(['物料单价表在这里!', item].join('--'));
        } else {
            return;
        }

        let codeIndex = itemSource.data[0].indexOf('编号');
        let unitPriceIndex = itemSource.data[0].indexOf('单价');
        if (!(codeIndex > -1 && unitPriceIndex > -1)) {
            console.log(['物料单价表好像有问题,', item].join('--'));
            return;
        }
        for (let i = 1; i < itemSource.data.length; i++) {
            if (itemSource.data[i][codeIndex] === null) {
                console.log(['这一项没有编码', item, '序号', itemSource.data[i][0]].join('--'))
                continue;
            }
            if (itemSource.data[i][unitPriceIndex] === null) {
                console.log(['这一项没有单价', item, '序号', itemSource.data[i][0]].join('--'))
            }
            data[itemSource.data[i][codeIndex]] = itemSource.data[i][unitPriceIndex]
        }
    });
    return data;
}
async function main() {
    const tarDir = path.join(__dirname, dataDir);
    const excludeFiles = []; //非数据日耗文件
    const allFileNames = fs.readdirSync(tarDir);
    const dataFileName = allFileNames.filter(item => {
        return !excludeFiles.includes(item);
    });
    let excelData = await getAllData(allFileNames);
    const sourceData = {};
    dataFileName.forEach(item => {
        sourceData[item] = JSON.parse(JSON.stringify(excelData[item]));
    }); // 需要提取表的数据
    let unitPriceData = await getUnitPriceData(sourceData, dataFileName);

    let extractData = await getExtractData(sourceData, dataFileName, unitPriceData);

    await buildExcel(extractData);
}
main();