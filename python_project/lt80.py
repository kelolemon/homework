from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ans = 1
        flag = 0
        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]:
                if flag == 0:
                    flag = 1
                    nums[ans] = nums[i]
                    ans = ans + 1
                else:
                    flag = flag + 1
            else:
                flag = 0
                nums[ans] = nums[i]
                ans = ans + 1
        return ans


if __name__ == '__main__':
    a = [1,1,1,2,2,3]
    m = Solution().removeDuplicates(a)
    print(a)
