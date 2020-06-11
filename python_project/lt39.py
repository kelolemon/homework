from typing import List


class Solution:
    ANS = set()
    SUB_ANS = []

    def find(self, step, res, candidates):
        if res == 0:
            self.ANS.add(tuple(self.SUB_ANS))
            return

        if step == len(candidates):
            return

        if candidates[step] <= res:
            res = res - candidates[step]
            self.SUB_ANS.append(candidates[step])
            self.find(step + 1, res, candidates)
            res = res + candidates[step]
            del self.SUB_ANS[-1]
        self.find(step + 1, res, candidates)

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ANS.clear()
        self.SUB_ANS = []
        candidates.sort()
        self.find(0, target, candidates)
        fin = []
        for x in self.ANS:
            fin.insert(len(fin), list(x))
        return fin


if __name__ == '__main__':
    candidates = [10,1,2,7,6,1,5]
    ta = 8
    print(Solution().combinationSum(candidates, ta))
