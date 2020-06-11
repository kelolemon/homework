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


if __name__ == '__main__':
    a = [2,1,5,6,2,3]
    print(Solution().largestRectangleArea(a))
