var isMatch = function(s, p) {
    let f = [];
    if (s.length === 0 && p.length === 0) {
        return true;
    }
    if (p.length === 0) return false;
    let begin = 0;
    if (s.length === 0) {
        if (p.length === 1) return false;
        while (p[begin + 1] === "*" && begin + 2 < p.length) begin = begin + 2;
        return begin + 2 === p.length && p[begin + 1] === "*";
    }
    for (let i = 0; i < s.length; i++) {
        f[i] = [];
        for (let j = 0; j < p.length; j++)
            f[i][j] = false;
    }
    if (s[0] === p[begin] || p[begin] === ".") f[0][begin] = true;
    while (p[begin + 1] === "*" && begin + 2 < p.length) {
        begin = begin + 2;
        if (s[0] === p[begin] || p[begin] === ".") f[0][begin] = true;
    }
    for (let i = 0; i < s.length; i++) {
        for (let j = 1; j < p.length; j++) {
            if (i > 0) f[i][j] = f[i][j] || (f[i - 1][j - 1] && s[i] === p[j]) || (f[i - 1][j - 1] && p[j] === ".");
            if (i > 0) f[i][j] = f[i][j] || (f[i - 1][j] && p[j] === "*" && (s[i] === p[j - 1] || p[j - 1] === "."));
            f[i][j] = f[i][j] || (f[i][j - 1] && p[j] === "*");
            if ((j - 2) >= 0)
                f[i][j] = f[i][j] || (p[j] === "*" && f[i][j - 2]);
        }
    }
    return f[s.length - 1][p.length - 1];
};