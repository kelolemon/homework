/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

const nums = [2, 7, 11, 15];
const tag = 9;

var twoSum = function(nums, target) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], i);
    }
    for (let i = 0; i < nums.length; i++) {
        let res = target - nums[i];
        if (!map.has(res)) continue;
        let ans = map.get(res);
        if (ans === i) continue;
        return [i, ans];
    }
};

console.log(twoSum(nums, tag));