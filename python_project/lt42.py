from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        ans = 0
        stack = []
        i = 0
        while i + 1 < len(height) and height[i] < height[i + 1]:
            i = i + 1
        stack.append((height[i], i))
        i = i + 1
        while i < len(height):
            if height[i] <= stack[-1][0]:
                stack.append((height[i], i))
            else:
                last_height = -1
                while len(stack) != 0 and stack[-1][0] < height[i]:
                    if last_height == -1:
                        last_height = stack[-1][0]
                    else:
                        ans = ans + (i - stack[-1][1] - 1) * (stack[-1][0] - last_height)
                        last_height = stack[-1][0]
                    stack.pop()
                if len(stack) != 0:
                    ans = ans + (i - stack[-1][1] - 1) * (height[i] - last_height)
                stack.append((height[i], i))
            i = i + 1
        return ans


if __name__ == '__main__':
    a = [2, 1, 0, 2]
    print(Solution().trap(a))
