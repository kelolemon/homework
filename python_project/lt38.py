class Solution:
    def countAndSay(self, n: int) -> str:
        ans = [""] * 100
        ans[1] = "1"
        ans[2] = "11"
        i = 2
        j = 0
        while i < n:
            time = 1
            while j + 1 < len(ans[i]) and ans[i][j] == ans[i][j + 1]:
                time = time + 1
                j = j + 1
            ans[i + 1] = ans[i + 1] + str(time)
            ans[i + 1] = ans[i + 1] + ans[i][j]
            j = j + 1
            if j == len(ans[i]):
                i = i + 1
                j = 0
        return ans[n]


if __name__ == '__main__':
    print(Solution().countAndSay(5))



