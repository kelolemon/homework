from typing import List


class Solution:
    ANS = []
    SUB_ASN = []
    set = 0
    tot = 0
    INF = 55

    def dfs(self, nums: List[int], step):
        if step == len(nums):
            self.ANS.append(self.SUB_ASN[:])
            return
        for i in range(0, len(nums)):
            if self.set & (1 << i) == 1 << i:
                continue
            self.SUB_ASN.append(nums[i])
            self.set |= 1 << i
            self.dfs(nums, step + 1)
            self.set ^= 1 << i
            del self.SUB_ASN[-1]

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ANS: List[List[int]]
        self.ANS = []
        self.tot = 0
        self.SUB_ASN = []
        self.dfs(nums, 0)
        temp = []
        for item in self.ANS:
            if item not in temp:
                temp.append(item)
        return temp


if __name__ == '__main__':
    a = [1, 1, 3]
    print(Solution().permute(a))
