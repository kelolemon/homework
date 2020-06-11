class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        for index in reversed(s):
            if index == ' ':
                if ans == 0:
                    continue
                return ans
            ans = ans + 1
        return ans


if __name__ == '__main__':
    a = "hello world"
    print(Solution().lengthOfLastWord(a))
