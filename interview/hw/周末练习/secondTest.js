// 1.请你设计并实现一个满足 LRU (最近最少使用) 缓存 约束的数据结构。
class LRUCache {
    constructor(num) {
        this.capacity = num;
        this.data = {};
        this.flag = 1;
    }
    put(key, val) {
        let newItem = null;
        if (Object.keys(this.data).length === 2 && !this.data[key]) {
            let outKey = this.findLastUseItem()
            delete this.data[outKey];
        }
        newItem = this.data[key] ?? new Array(3).fill(-1);
        newItem[0] = val;
        newItem[1] = key;
        this.data[key] = newItem;
        this.used(key);
    }
    used(key) {
        if (this.data[key]) {
            this.data[key][2] = this.flag++;
        }
    }
    findLastUseItem() {
        return Object.values(this.data).sort((a, b) => a[2] - b[2])[0][1];
    }
    get(key) {
        this.used(key);
        return this.data[key]?.[0] ?? -1;
    }
}
let lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
console.log(lRUCache.get(1)); // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
console.log(lRUCache.get(2)); // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
[1, 3, 4].forEach(item => {
    console.log(lRUCache.get(item))
})

console.log('--1题 end--')



// 2.给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃
// 到的最高金额。
// 思路：回溯
function getMaxMoney(arr = []) {
    let res = 0;
    backTack();
    return res;
    function backTack(start = 0, index = -2, val = 0) {
        if (start === arr.length) {
            res = Math.max(val, res);
        }
        for (let j = start; j < arr.length; j++) {
            for (let i = 1; i <= 2; i++) {
                if (i === 1 && j - 1 !== index) { //偷
                    backTack(j + 1, j, val + arr[j]);
                } else {
                    backTack(j + 1, index, val);
                }
            }
        }
    }
}
console.log(getMaxMoney([1, 2, 3, 1]), getMaxMoney([2, 7, 9, 3, 1]))

console.log('--2题 end--')
// 给你一棵二叉树的根节点 root ，返回树的 最大宽度。
// 中间为null的情况目前没法完全处理，一时之间没有思路，后续解决

function getMaxWidth(root = []) {
    let max = root ? 1 : 0;
    for (let i = 0; i < root.length; i = 2 * i + 1) {
        let count = 0;
        for (let j = i; j < 2 * i + 1; j++) {
            if (root[j] !== undefined) {
                count++
            }
        }
        max = Math.max(max, count)
    }
    return max;
}
[
    // [1, 3, 2, 5, 3, null, 9],
    // [1, 3, 2, 5],
    [1, 3, 2, 5, null, null, 9, 6, null, 7],
].forEach(item => {
    console.log(getMaxWidth(item))
})