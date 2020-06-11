var generateParenthesis = function(n) {
    n = n * 2;
    n = n - 1;
    let ans = [];
    for (let set = 0; set < 2 << n; set++) {
        let flag = 0;
        for (let i = 2 << (n - 1); i ; i = i >> 1) {
            if ((set & i) === i) flag = flag + 1; else flag = flag - 1;
            if (flag < 0) break;
        }
        if (flag === 0) {
            let sub_ans = "";
            for (let i = 2 << (n - 1); i ; i = i >> 1) {
                if ((set & i) === i) sub_ans = sub_ans + "(";
                else sub_ans = sub_ans + ")";
            }
            ans.push(sub_ans);
        }
    }
    return ans;
};

console.log(generateParenthesis(3));