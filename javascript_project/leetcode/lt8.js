/**
 * @param {string} str
 * @return {number}
 */

let regular = /[\-\+]?\d+/;

let s = "+-2";
var myAtoi = function(str) {
    str = str.trim();
    if (str[0] !== '-' && str[0] !== '+' && (str[0] < "0" || str[0] > "9")) return 0;
    let x = regular.exec(str);
    if (x) {
        console.log(x);
        x = parseInt(x);
        let MAX_INT = Math.pow(2, 31) - 1;
        let MIN_INT = - Math.pow(2, 31);
        return Math.max(Math.min(x, MAX_INT), MIN_INT);
    } else {
        return 0;
    }
};

console.log(myAtoi(s));