/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var threeSumClosest = function(nums, target) {
    nums = nums.sort((a, b) => {
        return a - b;
    });
    let min = 2e66, ans;
    for (let i = 1; i < nums.length - 1; i++) {
        let l = 0, r = nums.length - 1;
        while (l < i && r > i) {
            let tot = nums[i] + nums[l] + nums[r];
            if (Math.abs(tot - target) < min) {
                min = Math.abs(tot - target);
                ans = tot;
            }
            if (tot < target) l = l + 1;
            if (tot === target) return ans;
            if (tot > target) r = r - 1;
        }
    }
    return ans;
};

let a = [-1, 2, 1, -4];
let t = 1;

console.log(threeSumClosest(a, t));