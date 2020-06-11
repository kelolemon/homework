from typing import List


class Solution:
    ANS = []
    SUB_ANS = []
    SET = []
    number = []

    def search(self, step, now):
        if step == self.number:
            self.ANS.append(self.SUB_ANS[:])
            return
        if now >= len(self.SET):
            return
        self.SUB_ANS.append(self.SET[now])
        self.search(step + 1, now + 1)
        del self.SUB_ANS[-1]
        self.search(step, now + 1)

    def combine(self, n: int, k: int) -> List[List[int]]:
        set = [i + 1 for i in range(n)]
        self.SET = set
        self.ANS = []
        self.SUB_ANS = []
        self.number = k
        self.search(0, 0)
        return self.ANS


if __name__ == '__main__':
    n = 4
    k = 2
    print(Solution().combine(n, k))

