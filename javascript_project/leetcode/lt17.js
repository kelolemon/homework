/**
 * @param {string} digits
 * @return {string[]}
 */

const number = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
let sub_ans = "";
let ans = [];
let tot = 0;
const find = (digits, step) => {
    if (step === digits.length) {
        if (sub_ans.length > 0) ans.push(sub_ans);
        return;
    }
    for (let i = 0; i < number[digits[step]].length; i++) {
        sub_ans = sub_ans + number[digits[step]][i];
        find(digits, step + 1);
        sub_ans = sub_ans.substring(0, sub_ans.length - 1);
    }
};

var letterCombinations = function(digits) {
    ans = [];
    find(digits, 0);
    return ans;
};

let d = "";

console.log(letterCombinations(d));