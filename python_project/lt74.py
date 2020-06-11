from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        if m == 0:
            return False
        left = 0
        right = n
        while left + 1 < right:
            mid = (left + right) >> 1
            if matrix[mid][0] > target:
                right = mid - 1
            else:
                left = mid
        pos = left
        while pos + 1 < n and matrix[pos + 1][0] < target:
            pos = pos + 1
        left = 0
        right = m - 1
        while left <= right:
            mid = (left + right) >> 1
            if matrix[pos][mid] == target:
                return True
            if matrix[pos][mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return False

