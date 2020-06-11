var fourSum = function(nums, target) {
    nums.sort((a, b) => {
        return a - b;
    });
    let ans = [], tot = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) map.set(nums[i], i);
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            for (let k = j + 1; k < nums.length; k++){
                let res = nums[i] + nums[j] + nums[k];
                res = parseInt(target - res);
                if (map.has(res)) {
                    if (map.get(res) <= k) {
                        continue;
                    }
                    ans[tot] = [nums[i], nums[j], nums[k], res];
                    tot = tot + 1;
                }
                while (nums[k] === nums[k + 1]) k = k + 1;
            }
            while (nums[j] === nums[j + 1]) j = j + 1;
        }
        while (nums[i] === nums[i + 1]) i = i + 1;
    }
    return ans;
};

let n = [1, 0, -1, 0, -2, 2];
let t = 0;

console.log(fourSum(n, t));