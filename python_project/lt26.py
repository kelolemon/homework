from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for j in range(1, len(nums)):
            while j < len(nums) and nums[i] == nums[j]:
                j = j + 1
            i = i + 1
            if j < len(nums):
                nums[i] = nums[j]
        return i


if __name__ == '__main__':
    n = [1, 1, 2]
    a = Solution()
    print(Solution.removeDuplicates(a, n))

