let s = "";
let n = 4;
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    let row = [], now_row = 0, step = 1;
    if (numRows === 1) return s;
    for (let i = 0; i < s.length; i++) {
        //console.log(now_row);
        if (row[now_row])
            row[now_row] = row[now_row] + s[i];
        else
            row[now_row] = s[i];
        //console.log(row);
        if (now_row === numRows - 1 && step === 1) {
            step = -1;
        }
        if (now_row === 0 && step === -1) {
            step = 1;
        }
        now_row = now_row + step;
    }
    let z_string = "";
    for (let i = 0; i < numRows; i++) {
        if (row[i]) z_string = z_string + row[i];
    }
    return z_string;
};

console.log(convert(s, n));