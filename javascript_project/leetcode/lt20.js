/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [], top = -1;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "{" || s[i] === "[" || s[i] === "(") {
            stack[++top] = s[i];
        } else {
            if (s[i] === "}") {
                if (top >= 0 && stack[top] === "{") {
                    top--;
                    continue;
                }
                else return false;
            }
            if (s[i] === ")") {
                if (top >= 0 && stack[top] === "(") {
                    top--;
                    continue
                }
                else return false;
            }
            if (s[i] === "]") {
                if (top>=0 && stack[top] === "["){
                    top--;
                    continue;
                }
                else return false;
            }
        }
    }
    return top === -1;
};