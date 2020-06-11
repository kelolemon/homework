var intToRoman = function(num) {
    let roman = "";
    while (num >= 1000) {
        num = num - 1000;
        roman = roman + "M";
    }
    while (num >= 900) {
        num = num - 900;
        roman = roman + "CM";
    }
    while (num >= 500) {
        num = num - 500;
        roman = roman + "D";
    }
    while (num >= 400) {
        num = num - 400;
        roman = roman + "CD";
    }
    while (num >= 100) {
        num = num - 100;
        roman = roman + "C";
    }
    while (num >= 90) {
        num = num - 90;
        roman = roman + "XC";
    }
    while (num >= 50) {
        num = num - 50;
        roman = roman + "L";
    }
    while (num >= 40) {
        num = num - 40;
        roman = roman + "XL";
    }
    while (num >= 10) {
        num = num - 10;
        roman = roman + "X";
    }
    while (num >= 9) {
        num = num - 9;
        roman = roman + "IX";
    }
    while (num >= 5) {
        num = num - 5;
        roman = roman + "V";
    }
    while (num >= 4) {
        num = num - 4;
        roman = roman + "IV";
    }
    while (num >= 1) {
        num = num - 1;
        roman = roman + "I";
    }
    return roman;
};

console.log(intToRoman(1994));