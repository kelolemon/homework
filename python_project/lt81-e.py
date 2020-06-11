from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return False
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] == target:
                return True
            while left < mid and nums[left] == nums[mid]:
                left = left + 1
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return True if nums[left] == target else False
