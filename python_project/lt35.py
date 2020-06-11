from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            if target < nums[mid]:
                right = mid - 1
            else:
                if target == nums[mid]:
                    return mid
                else:
                    left = mid + 1
        return left if nums[left] >= target else left + 1


if __name__ == '__main__':
    a = [1, 3, 5, 6]
    target = 7
    print(Solution().searchInsert(a, target))

