const xlsx = require('node-xlsx');
const path = require('path');
const fs = require('fs-extra');
const { data } = require('jquery');

const dataDir = './data';
const date = new Date();
const dateData = [
    date.getFullYear(),
    date.getMonth() + 1,
    date.getDate()
]
async function getAllData(dir = []) {
    let data = {};
    dir.forEach(item => {
        let itemData = xlsx.parse(fs.readFileSync(path.join(__dirname, dataDir, item)));
        data[item] = itemData;
    });
    return data;
}
async function getExtractData(sourceData, dataFileName) {
    let data = {};
    dataFileName.forEach(item => {
        let itemSource = sourceData[item].find(item => item.name === '日耗表') //日料表数据;
        if (!itemSource) {
            String.prototype.startsWith
            if (!item.startsWith('.~')) {
                console.log(item, '这个表没有日耗表');
            }
            return;
        }
        let department = itemSource.data[1][0] === '部门' ? itemSource.data[1][1] : null; //部门
        {
            data[item] = { data: [], name: `${department}_日耗表` }
            let startIndex = 3;
            for (let i = startIndex; i < itemSource.data.length; i++) {
                let rowData = [
                    ...dateData, //'年', '月', '日'
                    department, // 部门
                    itemSource.data[i][1], //大类
                    itemSource.data[i][2], //存货名称
                    itemSource.data[i][4], //存货编码
                    '', //名称
                    '', //规格
                    '', //计量单位
                    parseInt(itemSource.data[i][6]) //当日发生数
                ];
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
        extractData[key].data.unshift(['年', '月', '日', '部门', '大类', '存货名称', '存货编码', '名称', '规格', '计量单位', '当日发生数'])
        return buildData.push(extractData[key]);
    });
    // const sheetOptions = { '!cols': [{ wch: 6 }, { wch: 7 }, { wch: 10 }, { wch: 20 }] };

    let buffer = xlsx.build(buildData, {}); // Returns a buffer
    fs.writeFileSync(path.join(__dirname, `./build/${dateData.join('_')}_各部门日耗表.xlsx`), buffer);
    console.log('-----生成日耗表成功!!');
}
async function main() {
    const tarDir = path.join(__dirname, dataDir);
    const excludeFiles = ['5月收支表及日耗.xlsx'];
    const allFileNames = fs.readdirSync(tarDir);
    const dataFileName = allFileNames.filter(item => {
        return !excludeFiles.includes(item);
    });
    let excelData = await getAllData(allFileNames);
    const sourceData = {};
    dataFileName.forEach(item => {
        sourceData[item] = JSON.parse(JSON.stringify(excelData[item]));
    }) // 需要提取表的数据
    let extractData = await getExtractData(sourceData, dataFileName);

    await buildExcel(extractData);
}
main();