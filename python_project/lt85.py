from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if not heights:
            return 0
        n = len(heights)
        left = [0] * n
        right = [0] * n
        stack = [0]
        for i in range(1, n):
            while len(stack) != 0 and heights[i] < heights[stack[-1]]:
                left[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        while len(stack) != 0:
            left[stack[-1]] = n - stack[-1]
            stack.pop()

        stack = [n - 1]
        for i in range(1, n):
            while len(stack) != 0 and heights[n - i - 1] < heights[stack[-1]]:
                right[stack[-1]] = stack[-1] + i - n
                stack.pop()
            stack.append(n - i - 1)

        while len(stack) != 0:
            right[stack[-1]] = stack[-1]
            stack.pop()
        ans = 0
        for i in range(n):
            ans = max(ans, (right[i] + left[i]) * heights[i])
        return ans

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        if m == 0:
            return 0
        dp = [0] * m
        ans = 0
        for i in range(0, n):
            for j in range(0, m):
                dp[j] = dp[j] + 1 if matrix[i][j] == "1" else 0
            ans = max(ans, self.largestRectangleArea(dp))
        return ans


if __name__ == '__main__':
    f = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
    print(Solution().maximalRectangle(f))
