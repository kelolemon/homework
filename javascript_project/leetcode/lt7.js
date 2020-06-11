/**
 * @param {number} x
 * @return {number}
 */

let x = 123;

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
    if (number < - Math.pow(2, 31) || number > Math.pow(2, 31) - 1) {
        //console.log(number);
        return 0;
    }
    return number;
};

console.log(reverse(x));