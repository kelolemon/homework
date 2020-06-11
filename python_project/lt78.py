from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        for set in range(1 << n):
            sub_ans = []
            for i in range(n):
                if set & (1 << i) == 1 << i:
                    sub_ans.append(nums[i])
            ans.append(sub_ans[:])
        return ans

