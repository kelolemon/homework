from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        left = 0
        right = len(nums) - 1
        for i in range(0, len(nums)):
            while left<= i <= right and nums[i] != 1:
                if nums[i] == 0:
                    nums[left], nums[i] = nums[i], nums[left]
                    left += 1
                if nums[i] == 2:
                    nums[right], nums[i] = nums[i], nums[right]
                    right -= 1
            if i >= right:
                break
        return

