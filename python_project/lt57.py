from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        ans = []
        if not intervals:
            return ans
        intervals.sort(key=lambda x: x[0])
        left = intervals[0][0]
        right = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= right:
                right = max(right, intervals[i][1])
            else:
                ans.append([left, right])
                left = intervals[i][0]
                right = intervals[i][1]
        ans.append([left, right])
        return ans


if __name__ == '__main__':
    a = [[1,4],[4,5]]
    print(Solution().merge(a))

