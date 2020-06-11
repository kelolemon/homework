from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_bound = nums[0]
        for i in range(1, len(nums)):
            if i > max_bound:
                return False
            max_bound = max(max_bound, i + nums[i])
        if max_bound >= len(nums) - 1:
            return True
        return False


if __name__ == '__main__':
    a = [3,2,1,0,4]
    print(Solution().canJump(a))
