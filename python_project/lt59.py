from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        point = (0, 0)
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        now = 0
        for i in range(0, n * n):
            ans[point[0]][point[1]] = i + 1
            if point[0] + dx[now] >= n or point[1] + dy[now] >= n or point[0] + dx[now] < 0 or point[1] + dy[now] < 0 \
                    or ans[point[0] + dx[now]][point[1] + dy[now]] != 0:
                now = 0 if now == 3 else now + 1
            point = (point[0] + dx[now], point[1] + dy[now])
        return ans


if __name__ == '__main__':
    n = 3
    print(Solution().generateMatrix(n))
