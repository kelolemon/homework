from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = 0
        if not nums:
            return 0
        f = [nums[0]]
        for i in range(1, len(nums)):
            f.append(max(f[-1] + nums[i], nums[i]))
        return max(f)


if __name__ == '__main__':
    a = [-2,1,-3,4,-1,2,1,-5,4]
    print(Solution().maxSubArray(a))
