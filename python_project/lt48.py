from typing import List


class Solution:
    def swap(self, a, b):
        return b, a

    def rotate(self, matrix: List[List[int]]) -> None:
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[i])):
                if i <= j:
                    continue
                matrix[i][j], matrix[j][i] = self.swap(matrix[i][j], matrix[j][i])
        for i in range(0, len(matrix)):
            matrix[i].reverse()
        return


if __name__ == '__main__':
    matrix =[
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    Solution().rotate(matrix)
    print(matrix)
