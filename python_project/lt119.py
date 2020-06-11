from typing import List


class Solution:
    def getFac(self, n: int) -> int:
        if n == 0:
            return 1
        ans = 1
        for i in range(2, n + 1):
            ans *= i
        return ans

    def getCom(self, n: int, m: int) -> int:
        x = self.getFac(m)
        y = self.getFac(n)
        z = self.getFac(m - n)
        return x // (y * z)

    def getRow(self, rowIndex: int) -> List[int]:
        ans = []
        for i in range(0, rowIndex + 1):
            ans.append(self.getCom(i, rowIndex))
        return ans
