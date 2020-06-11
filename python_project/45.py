from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        max_pos = 0
        max_arrive = 0
        ans = 0
        for i in range(0, len(nums) - 1):
            max_arrive = max(max_arrive, nums[i] + i)
            if i >= max_pos:
                max_pos = max_arrive
                ans = ans + 1
        return ans


if __name__ == '__main__':
    a = [2,3,1,1,4]
    print(Solution().jump(a))
