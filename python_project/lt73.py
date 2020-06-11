from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        col = 0
        row = 0
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                if matrix[i][j] == 0:
                    col |= 1 << i
                    row |= 1 << j
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                if col & 1 << i == 1 << i or row & 1 << j == 1 << j:
                    matrix[i][j] = 0
        return
