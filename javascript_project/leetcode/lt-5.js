/**
 * @param {string} s
 * @return {string}
 */

let s = "afkfkfkaaaafkfk";

var longestPalindrome = function(s) {
    let f = "&#";
    for (let i = 0;i < s.length; i++){
        f = f + s[i];
        f = f + "#";
    }
    let length = [];
    let max_right = 0, max_length = 0, pos = 0, max_pos = 0;
    for (let i = 1;i < f.length;i++) {
        if (i < max_right) {
            length[i] = Math.min(max_right - i, length[2 * pos - i]);
        } else length[i] = 1;
        while (i - length[i] >=0 && i + length[i] < f.length && f[i - length[i]] === f[i + length[i]]){
            length[i] = length[i] + 1;
        }
        if (i + length[i] - 1 > max_right) {
            max_right = i + length[i] - 1;
            pos = i;
        }
        if (length[i] > max_length) {
            max_length = length[i];
            max_pos = i;
        }
    }
    let max_sub_string = f.substring(max_pos - max_length + 1, max_pos + max_length);
    let real_sub = "";
    for (let i = 0;i < max_sub_string.length;i++) {
        if (max_sub_string[i] === "#") continue;
        real_sub = real_sub + max_sub_string[i];
    }
    return real_sub;
};

console.log(longestPalindrome(s));