from typing import List


class Solution:
    COL = [0] * 10
    ROW = [0] * 10
    BLOCK = [0] * 10
    Flag = 0

    def solve(self, board: List[List[str]], i, j):
        if self.Flag == 1:
            return
        if j == 9:
            self.solve(board, i + 1, 0)
            return
        if i == 9:
            self.Flag = 1
            return
        if board[i][j] != ".":
            self.solve(board, i, j + 1)
            return
        for x in range(1, 10):
            if self.COL[i] & (1 << x) == 1 << x or self.ROW[j] & (1 << x) == 1 << x or \
                    self.BLOCK[int(i / 3) * 3 + int(j / 3)] & (1 << x) == 1 << x:
                continue
            board[i][j] = str(x)
            self.COL[i] = self.COL[i] | (1 << x)
            self.ROW[j] = self.ROW[j] | (1 << x)
            self.BLOCK[int(i / 3) * 3 + int(j / 3)] = self.BLOCK[int(i / 3) * 3 + int(j / 3)] | (1 << x)
            self.solve(board, i, j + 1)
            if self.Flag == 1:
                return
            self.COL[i] = self.COL[i] ^ (1 << x)
            self.ROW[j] = self.ROW[j] ^ (1 << x)
            self.BLOCK[int(i / 3) * 3 + int(j / 3)] = self.BLOCK[int(i / 3) * 3 + int(j / 3)] ^ (1 << x)
            board[i][j] = "."

    def solveSudoku(self, board: List[List[str]]) -> None:
        for i in range(0, 10):
            self.COL[i] = 0
            self.ROW[i] = 0
            self.BLOCK[i] = 0
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] == ".":
                    continue
                self.COL[i] = self.COL[i] | (1 << int(board[i][j]))
                self.ROW[j] = self.ROW[j] | (1 << int(board[i][j]))
                self.BLOCK[int(i / 3) * 3 + int(j / 3)] = self.BLOCK[int(i / 3) * 3 + int(j / 3)] | (1 << int(board[i][j]))
        self.solve(board, 0, 0)


if __name__ == '__main__':
    bd = [[".", ".", "9", "7", "4", "8", ".", ".", "."], ["7", ".", ".", ".", ".", ".", ".", ".", "."],
     [".", "2", ".", "1", ".", "9", ".", ".", "."], [".", ".", "7", ".", ".", ".", "2", "4", "."],
     [".", "6", "4", ".", "1", ".", "5", "9", "."], [".", "9", "8", ".", ".", ".", "3", ".", "."],
     [".", ".", ".", "8", ".", "3", ".", "2", "."], [".", ".", ".", ".", ".", ".", ".", ".", "6"],
     [".", ".", ".", "2", "7", "5", "9", ".", "."]]
    print(Solution().solveSudoku(bd))
    print(bd)
