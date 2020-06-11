var longestCommonPrefix = function(strs) {
    let length = 0;
    let string = "";
    if (strs.length === 0) return string;
    while (true) {
        let flag = 0;
        if (strs[0].length === 0) return string;
        let test_char = strs[0][length];
        for (let i = 1; i < strs.length; i++) {
            if (strs[i].length === 0) return string;
            if (test_char !== strs[i][length]) {
                flag = 1;
                break;
            }
        }
        if (flag === 1) break;
        length = length + 1;
        if (test_char === undefined) return string;
        string = string + test_char;
    }
    return string;
};

let st = ["c", "c"];

console.log(longestCommonPrefix(st));