from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        if not matrix:
            return ans
        n = len(matrix)
        m = len(matrix[0])
        point = (0, 0)
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        now = 0
        for i in range(0, n * m):
            ans.append(matrix[point[0]][point[1]])
            matrix[point[0]][point[1]] = -141231512
            if point[0] + dx[now] >= n or point[1] + dy[now] >= m or point[0] + dx[now] < 0 or point[1] + dy[now] < 0 \
                    or matrix[point[0] + dx[now]][point[1] + dy[now]] == -141231512:
                now = 0 if now == 3 else now + 1
            point = (point[0] + dx[now], point[1] + dy[now])
        return ans


if __name__ == '__main__':
    a = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9,10,11,12]
    ]
    print(Solution().spiralOrder(a))
