/**
 * @param {number} x
 * @return {boolean}
 */

let x = 11221;
var reverse = function(x) {
    let flag = 0;
    if (x < 0) {
        flag = 1;
        x = x * -1;
    }
    let number = 0;
    while (x !== 0) {
        //console.log(number, x);
        number = number * 10 + (x % 10);
        x = parseInt(x / 10);
    }
    if (flag === 1) number = -number;
    return number;
};

var isPalindrome = function(x) {
    if (x < 0) return false;
    let re_x = reverse(x);
    return x === re_x;

};

console.log(isPalindrome(x));