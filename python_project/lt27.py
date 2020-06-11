from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        for i in range(0, len(nums)):
            if nums[i] == val:
                del nums[i]
        return len(nums)
