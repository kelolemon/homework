/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let map = new Map();
    let l = 0;
    let r = 1;
    let max_length = s.length;
    let max_ans = 1;
    let substring = s.substring(l, r);
    map.set(s[l], 1);
    while (r < max_length) {
        if (!map.has(s[r])) {
            //console.log(r, s[r]);
            map.set(s[r], 1);
            r++;
            if (r - l > max_ans) {
                max_ans = r - l;
                substring = s.substring(l, r);
                //console.log(substring);
            }
        } else {
            //console.log(l);
            map.delete(s[l]);
            l++;
        }
    }
    return substring.length;
};