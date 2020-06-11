from typing import List


class Solution:
    def bin_search(self, a:List[int], l:int, r:int, target:int, ans:List[int]):
        if l > r:
            return
        mid = (l + r) >> 1
        if a[l] == target:
            ans[0] = min(ans[0], l)
            ans[1] = max(ans[1], l)
        if a[r] == target:
            ans[0] = min(ans[0], r)
            ans[1] = max(ans[1], r)
        if ans[0] < mid < ans[1]:
            return
        if target == a[mid]:
            ans[0] = min(ans[0], mid)
            ans[1] = max(ans[1], mid)
            self.bin_search(a, l, mid - 1, target, ans)
            self.bin_search(a, mid + 1, r, target, ans)
            return
        else:
            if target > a[mid]:
                self.bin_search(a, mid + 1, r, target, ans)
            else:
                self.bin_search(a, l, mid - 1, target, ans)

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ans = [200000000, -1]
        self.bin_search(nums, 0, len(nums) - 1, target, ans)
        if ans[1] == -1:
            return [-1, -1]
        else:
            return ans


if __name__ == '__main__':
    nums = [7, 7, 7, 7, 7, 7, 10]
    target = 7
    print(Solution().searchRange(nums, target))


