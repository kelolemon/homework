var romanToInt = function(s) {
    let number = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "C" && s[i + 1] === "M") {
            number += 900;
            i = i + 1;
            continue;
        }
        if (s[i] === "C" && s[i + 1] === "D") {
            number += 400;
            i = i + 1;
            continue;
        }
        if (s[i] === "X" && s[i + 1] === "C") {
            number += 90;
            i = i + 1;
            continue;
        }
        if (s[i] === "X" && s[i + 1] === "L") {
            number += 40;
            i = i + 1;
            continue;
        }
        if (s[i] === "I" && s[i + 1] === "X") {
            number += 9;
            i = i + 1;
            continue;
        }
        if (s[i] === "I" && s[i + 1] === "V") {
            number += 4;
            i = i + 1;
            continue;
        }
        if (s[i] === "I") number += 1;
        if (s[i] === "V") number += 5;
        if (s[i] === "X") number += 10;
        if (s[i] === "L") number += 50;
        if (s[i] === "C") number += 100;
        if (s[i] === "D") number += 500;
        if (s[i] === "M") number += 1000;
    }
    return number;
};

console.log(romanToInt("MCMXCIV"));