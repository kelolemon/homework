from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums:
            return 1
        nums.insert(len(nums), 0)
        for i in range(0, len(nums)):
            while True:
                if nums[i] <= 0 or nums[i] >= len(nums) or nums[i] == i:
                    break
                a, b = nums[nums[i]], nums[i]
                if a == b:
                    break
                nums[nums[i]], nums[i] = b, a
        for i in range(1, len(nums)):
            if nums[i] != i:
                return i
        return len(nums)


if __name__ == '__main__':
    a = [7, 8, 9, 11, 12]
    print(Solution().firstMissingPositive(a))
    print(a)

