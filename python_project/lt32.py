class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * len(s)
        for i in range(0, len(s)):
            if s[i] == "(":
                dp[i] = 0
            else:
                if i > 0 and s[i - 1] == "(":
                    if i > 1:
                        dp[i] = dp[i - 2] + 2
                    else:
                        dp[i] = 2
                else:
                    if i > 2 and i - dp[i - 1] - 1 >= 0 and s[i - dp[i - 1] - 1] == "(":
                        dp[i] = dp[i - 1] + 2 + (dp[i - dp[i - 1] - 2] if i > 3 else 0)
                    else:
                        dp[i] = 0
        max_ans = 0
        print(dp)
        for i in range(0, len(dp)):
            max_ans = max(dp[i], max_ans)
        return max_ans


if __name__ == '__main__':
    s = "(()))())("
    print(Solution().longestValidParentheses(s))

