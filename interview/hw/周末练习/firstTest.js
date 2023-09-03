// 第1题 括号是否匹配
// 思路：栈的使用；
function isValidStr(str = "") {
    let stack = [];
    let enter = ['(', '{', '['];
    let out = [')', '}', ']'];
    for (let i = 0; i < str.length; i++) {
        if (enter.includes(str[i])) {
            stack.push(str[i]);
        }
        if (out.includes(str[i])) {
            let lastChar = stack.pop();
            if (enter.indexOf(lastChar) !== out.indexOf(str[i])) {
                return false;
            }
        }
    }
    return stack.length === 0;
}
console.log(isValidStr('{{fafa()[]}}'), isValidStr("(]"));

// 第2题 无重复字符的最长子串
// 思路：双指针
function getMaxLengthSubStr(str = "") {
    let res = [0, 1];
    for (let i = 0, j = 1; j < str.length;) {
        let repeatIndex = str.substring(i, j).indexOf(str[j])
        if (repeatIndex !== -1) {
            i += (repeatIndex + 1);
            j++;
        } else {
            j++;
        }
        if (res[1] - res[0] < j - i) {
            res[0] = i;
            res[1] = j;
        }
    }
    return res[1] - res[0];
}
console.log(getMaxLengthSubStr("abcabcbb"), getMaxLengthSubStr("bbbbb"), getMaxLengthSubStr("pwwkew"));

// 第3题 最短路径和
// 思路：回溯
function getMinLengthRoad(grid = [[]]) {
    let row = grid.length;
    let col = grid[0].length;
    let res = Infinity;
    backTack([0, 0], grid[0][0]);
    return res;
    function backTack(road, val) {
        if (road[0] === row - 1 && col - 1 === road[1]) {
            res = Math.min(res, val)
            return;
        }
        for (let i = 1; i <= 2; i++) {
            if (i === 1 && road[0] !== row - 1) {
                road[0]++;
                backTack(road, val + grid[road[0]][road[1]]);
                road[0]--;
            } else if (road[1] !== col - 1) {
                road[1]++
                backTack(road, val + grid[road[0]][road[1]]);
                road[1]--
            }
        }
    }

}
console.log(
    getMinLengthRoad(
        [
            [1, 3, 1], [1, 5, 1], [4, 2, 1]
        ]
    ),
    getMinLengthRoad(
        [
            [1, 2, 3],
            [4, 5, 6]
        ]

    ))