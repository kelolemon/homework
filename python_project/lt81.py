from typing import List


class Solution:
    def check(self, nums, left, right):
        if left == right:
            return True
        if right - left == 1 and nums[left] == nums[right]:
            return True
        if nums[left] < nums[right]:
            return True
        if nums[left] == nums[right]:
            mid = (left + right) >> 1
            return self.check(nums, left, mid) and self.check(nums, mid, right)
        return False

    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return False
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if nums[mid] == target:
                return True
            if self.check(nums, left, mid):
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


if __name__ == '__main__':
    a = [1,3,1,1,1]
    b = 3
    print(Solution().search(a, b))
