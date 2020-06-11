/**
 * @param {number[]} height
 * @return {number}
 */

let a = [1,8,6,2,5,4,8,3,7];
var maxArea = function(height) {
    let l = 0;
    let r = height.length - 1;
    let max_area = 0;
    while (l !== r) {
        max_area = Math.max(max_area, (r - l) * Math.min(height[l], height[r]));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return max_area;
};

console.log(maxArea(a));