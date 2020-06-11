s = "aa";
p = "a";
var isMatch = function(s, p) {
    let re = new RegExp(p);
    return re.exec(s)!== null && re.exec(s)[0] === s;
};

console.log(isMatch(s, p));