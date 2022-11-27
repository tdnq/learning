// ==UserScript==
// @name         试用报告管理_显示价格
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        http://user.shikee.com/seller/report/rlist/*
// @match        https://trade.taobao.com/trade/itemlist/list_sold_items.htm?action=itemlist/SoldQueryAction&event_submit_do_query=1&auctionStatus=REFUNDING&tabCode=refunding
// @match        https://trade.taobao.com/trade/itemlist/list_sold_items.htm*
// @match        https://www.jinpaishike.com/index.php?m=Member&c=Order&a=order_manage&mod=trial&state=1&status=3*
// @match        https://www.jinpaishike.com/user/order/?goods_id=*&mod=trial&state=1&status=3*
// @grant        GM_xmlhttpRequest
// @grant        GM_getValue
// @grant        GM_setValue
// @require      https://cdn.bootcdn.net/ajax/libs/jquery/3.5.1/jquery.min.js
// ==/UserScript==

(function () {
    'use strict';
    // 获取数据--金牌食客
    if (location.href.startsWith('https://www.jinpaishike.com/')) {
        let orders = new Array();
        for (let i = 0; i < $(".tc>li>span").length; i += 2) {
            let oid = $(".tc>li>span")[i].innerHTML;
            orders.push({ id: oid, price: '0.00', url: '' });
        }
        console.log(orders);
        GM_setValue("dy_orders", JSON.stringify(orders));
    }
   // 获取数据-试客联盟
    if (location.href.startsWith("http://user.shikee.com/seller/report/")) {
        function sleep(time) {
            return new Promise((resolve) => setTimeout(resolve, time));
        }
        sleep(1000).then(() => {
            let orders = new Array();
            let ele = document.querySelector("table.ui-table").querySelectorAll("tr");
            let idsEle=[];
            for(let i=1;i<ele.length;i++){
                let idText=ele[i].querySelectorAll("td")[4].innerText;
                idsEle.push(idText);
            }
            console.log(idsEle);
            for (let i = 0; i < idsEle.length; ++i) {
                orders.push({ id:  idsEle[i]});

            }
           GM_setValue("dy_orders", JSON.stringify(orders));
        });
    }
    if (location.href.startsWith('https://trade.taobao.com/')) {
        $(
            '<div style="border: 2px dashed rgb(0, 85, 85);  position: fixed; top: 0; right: 0; z-index: 99999; background-color: rgba(239, 247, 253, 0.85); overflow-x: auto;">' +
            '<span style="font-size: medium;"></span>' +
            '<div style="font-size: medium;">审核订单</div>' +
            '<button style="margin-right: 10px;" id="dy_compare_data">一键对比数据</button>' +
            '<button style="margin-right: 10px;" id="dy_open_jpage">打开审核页面（满足条件）</button>' +
            '<div style="max-height: 300px; overflow-y: auto;">' +
            '<table border="1" style="font-size: 12px;" id="dy_orders_table">' +
            '<thead>' +
            '<tr>' +
            '<th style="width: 25px; min-width: 25px;">序号</th>' +
            '<th style="min-width: 150px;">订单号</th>' +
            '<th style="min-width: 80px;">订单状态（淘宝）</th>' +
            '<th style="min-width: 80px;">价格（试客联盟）</th>' +
            '<th style="min-width: 80px;">价格（淘宝）</th>' +
            '</tr>' +
            '</thead>' +
            '<tbody>' +
            '<tr>' +
            '<td colspan="3" style="display: none;"></td>' +
            '</tr>' +
            '</tbody>' +
            '</table>' +
            '</div>' +
            '</div>'
        ).appendTo('body');

        function appendRow(index, oid, status, price_shikee, price_taobao, url) {
            $(
                '<tr>' +
                `<td><a target="_blank" href="${url}">${index}</a></td>` +
                `<td>${oid}</td>` +
                `<td>${status}</td>` +
                `<td>￥${price_shikee}</td>` +
                `<td>￥${price_taobao}</td>` +
                '</tr>'
            ).appendTo($('#dy_orders_table'));
        }

        //数据获取
        function ab2str(arrayBuf, encodeType) {
            var decoder = new TextDecoder(encodeType)
            var u8arr = new Uint8Array(arrayBuf)
            return decoder.decode(u8arr)
        }
        var good_orders = new Array();

        //开始比对
        $('#dy_compare_data').click(() => {
            //document.getElementsByClassName('aw-window')[0].style.display= 'none';
            var orders = JSON.parse(GM_getValue("dy_orders"));
            console.log(orders);
            for (let i = 0; i < orders.length; ++i) {

                fetch("https://trade.taobao.com/trade/itemlist/asyncSold.htm?event_submit_do_query=1&_input_charset=utf8&",
                      {
                        "credentials": "include",
                        "headers": {
                            "accept": "application/json, text/javascript, */*; q=0.01",
                            "accept-language": "zh-CN,zh;q=0.9",
                            "content-type": "application/x-www-form-urlencoded; charset=UTF-8",
                            "sec-fetch-mode": "cors",
                            "sec-fetch-site": "same-origin",
                            "x-requested-with": "XMLHttpRequest",

                            "content-length": 488,
                            "origin":"https://trade.taobao.com"
                        },
                        "referrer": "https://trade.taobao.com/trade/itemlist/list_sold_items.htm?spm=a1z09.1.a1zvp.2.5b353606OBw2Zl",
                        "referrerPolicy": "no-referrer-when-downgrade",
                        "body": `auctionType=0&close=0&pageNum=1&pageSize=15&queryMore=true&rxAuditFlag=0&rxElectronicAllFlag=0&rxElectronicAuditFlag=0&rxHasSendFlag=0&rxOldFlag=0&rxSendFlag=0&rxSuccessflag=0&rxWaitSendflag=0&showQueryTag=true&tradeTag=0&useCheckcode=false&useOrderInfo=false&errorCheckcode=false&action=itemlist%2FSoldQueryAction&orderId=${orders[i].id}&prePageNo=1&buyerNick=&dateBegin=0&dateEnd=0&logisticsService=&orderStatus=&queryOrder=desc&rateStatus=&refund=&sellerNick=&tabCode=latest3Months`,
                        "method": "POST",
                        "mode": "cors"
                    })
                     .then(
                        response => {  let temp = response.arrayBuffer(); return temp }
                    )
                    .then(
                        raw => { let temp = ab2str(raw, 'gbk'); return temp }
                    )
                    .then(
                        str =>{ let temp=JSON.parse(str);console.log("str",temp);return temp}
                    )
                    .then(content => {

                        var tb_status = content.mainOrders[0].statusInfo.text;
                        var tb_price = content.mainOrders[0].payInfo.actualFee;
                        appendRow(i + 1, orders[i].id, tb_status, orders[i].price, tb_price, orders[i].url);
                         if (tb_status === '交易成功') {
                            good_orders.push({ url: orders[i].url });
                             console.log("sucess",tb_status,orders[i].id);
                        }
                    });

            }
        });
        $('#dy_open_jpage').click(() => {
            for (var i = 0; i < good_orders.length; ++i) {
                window.open(good_orders[i].url);
            }
        });
    }
})();