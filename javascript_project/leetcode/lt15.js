/**
 * @param {number[]} nums
 * @return {number[][]}
 */

let a = [0, 0, 0, 0];
var threeSum = function(nums) {
    nums.sort((a, b) => {
        return a - b;
    });
    let ans = [], tot = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) map.set(nums[i], i);
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            let res = nums[i] + nums[j];
            res = parseInt(0 - res);
            if (map.has(res)) {
                if (map.get(res) <= j) {
                    continue;
                }
                ans[tot] = [nums[i], nums[j], res];
                tot = tot + 1;
            }
            while (nums[j] === nums[j + 1]) j = j + 1;
        }
        while (nums[i] === nums[i + 1]) i = i + 1;
    }
    return ans;
};

console.log(threeSum(a));