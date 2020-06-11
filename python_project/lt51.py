from typing import List


class Solution:
    ANS = 0
    x = 0
    y = 0
    row = 0

    def search(self, step, n):
        if step == n:
            self.ANS += 1
            return
        for i in range(0, n):
            if self.row & (1 << i) == 1 << i:
                continue
            if self.x & (1 << (step + i)) == 1 << (step + i):
                continue
            if self.y & (1 << (step - i + 2 * n)) == 1 << (step - i + 2 * n):
                continue
            self.row |= 1 << i
            self.x |= 1 << (step + i)
            self.y |= 1 << (step - i + 2 * n)
            self.search(step + 1, n)
            self.row ^= 1 << i
            self.x ^= 1 << (step + i)
            self.y ^= 1 << (step - i + 2 * n)

    def totalNQueens(self, n: int) -> int:
        self.ANS = 0
        self.search(0, n)
        return self.ANS


if __name__ == '__main__':
    n = 4
    print(Solution().totalNQueens(n))
