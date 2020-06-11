from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            flag = [0] * 10
            for j in range(0, 9):
                if board[i][j] == ".":
                    continue
                if flag[int(board[i][j])] == 0:
                    flag[int(board[i][j])] = 1
                else:
                    return False
        j = 0
        while j < 9:
            flag = [0] * 10
            for i in range(0, 9):
                if board[i][j] == ".":
                    continue
                if flag[int(board[i][j])] == 0:
                    flag[int(board[i][j])] = 1
                else:
                    return False
            j = j + 1
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                flag = [0] * 10
                for step_i in range(0, 3):
                    for step_j in range(0, 3):
                        if board[i + step_i][j + step_j] == ".":
                            continue
                        if flag[int(board[i + step_i][j + step_j])] == 0:
                            flag[int(board[i + step_i][j + step_j])] = 1
                        else:
                            return False
        return True
