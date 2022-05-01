// ==UserScript==
// @name         添加脚本活动
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        www.51fanzan.com/Task*
// @grant        GM_xmlhttpRequest
// @grant        GM_getValue
// @grant        GM_setValue
// @grant        GM_addStyle
// ==/UserScript==

(function () {
    'use strict';
    const tarUrl = 'www.51fanzan.com/Task/add.html';
    if (!location.href.includes(tarUrl)) {
        return;
    }
    let tar = ['date', 'time', 'num'];
    const DATE = new Date();
    const DateData = {
        mouth: DATE.getMonth() + 1,
        day: DATE.getDate(),
        year: DATE.getFullYear(),
        hour: DATE.getHours(),
        minute: DATE.getMinutes()
    }
    DateData.mouth = String(DateData.mouth).length === 1 ? `0${DateData.mouth}` : DateData.mouth;
    DateData.day = String(DateData.day).length === 1 ? `0${DateData.day}` : DateData.day;
    DateData.hour = String(DateData.hour).length === 1 ? `0${DateData.hour}` : DateData.hour;
    DateData.minute = String(DateData.minute).length === 1 ? `0${DateData.minute}` : DateData.minute;

    // init html
    const root = document.createElement('div');
    GM_addStyle(`
        .autoScript_main {
                    width: 260px;
                    height: auto;
                    padding: 1rem 0.5rem;
                    border: 1px solid rgb(158, 148, 148);
                    box-shadow: 1px 2px #c7d1f7;
                    position: fixed;
                    top: 1rem;
                    right: 1rem;
                    z-index: 1000;
                    background-color: #e8e2ef;
            }
            .autoScript_main>div>button {
                float: right;
                margin: 20px 10px 0;
            }
    ` );
    root.innerHTML = `
    <div class="autoScript_main">
        <h4>脚本-填写数据:</h4>
        <label>日期:</label>
        <input value='${DateData.year}-${DateData.mouth}-${DateData.day}' id='autoScript_date' type="text">
        <br />
         <label>时间:</label>
        <input value='10:00' id='autoScript_time'>
        <br />
        <label>间隔:</label>
        <input id='autoScript_interval' value='30' type="number">
        <br />
        <label>期数:</label>
        <input value = '${5}' id='customItem' type="number">
        <br />
        <label>份数:</label>
        <input value = '${1}' id='autoScript_num' type="number">
        <br />
        <div>
           <button id="clear">清空</button>
           <button id = 'confirm'>确认</button>
       </div>
       <div class='info' style="color: red" ></div>
    </div>
    `;
    document.body.appendChild(root);

    // event listen
    document.querySelector(".autoScript_main button#confirm").addEventListener('click', function () {
        document.querySelector(".autoScript_main>.info").textContent = "";
        let values = {};
        tar.forEach((item, index) => {
            values[item] = document.querySelector(`#autoScript_${item}`).value;
        });
        let prevLen = document.querySelectorAll('.step_block.batch_box>div>.batch_fs_box').length;
        for (let i = 0; i < document.querySelector('#customItem').value - 0; i++) {
            document.querySelector('.step_block.batch_box .release_btn').click();
        }
        fillData(values, prevLen);
    })
    document.querySelector(".autoScript_main button#clear").addEventListener('click', function () {
        document.querySelectorAll('.step_block.batch_box>div>.batch_fs_box .delete_btn').forEach(item => {
            item.click();
        })
    })

    function fillData(data, prevLen) {
        data.time = new Date(parseInt(DateData.year), parseInt(DateData.mouth), parseInt(DateData.day), parseInt(data.time.split(':')[0]), parseInt(data.time.split(':')[1]));
        const eleItems = document.querySelectorAll('.step_block.batch_box>div>.batch_fs_box');

        let interval = parseInt(document.querySelector(`#autoScript_${'interval'}`).value);
        for (let i = prevLen; i < eleItems.length; i++) {
            let tempDate = new Date(data.time.getTime() + (i - prevLen) * interval * 60 * 1000);
            tar.forEach((item, index) => {
                let val = data[item];
                if (item === 'time') {
                    let hour = tempDate.getHours();
                    let minute = tempDate.getMinutes();
                    hour = String(hour).length === 1 ? '0' + hour : hour;
                    minute = String(minute).length === 1 ? '0' + minute : minute;
                    eleItems[i].querySelectorAll(`input`)[index].value = `${hour}:${minute}`;
                } else {
                    eleItems[i].querySelectorAll(`input`)[index].value = val;
                }
                eleItems[i].querySelectorAll(`input`)[index].dispatchEvent(new Event('change'));
            });
        }
        document.querySelector(".autoScript_main>.info").textContent = "!操作成功";
    }
})();