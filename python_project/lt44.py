class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not s and p:
            for i in range(0, len(p)):
                if p[i] != "*":
                    return False
            return True
        if s and not p:
            return False
        if not s and not p:
            return True
        f = [[False] * (len(p)) for _ in range(len(s))]
        if s[0] == p[0] or p[0] == "*" or p[0] == "?":
            f[0][0] = True
        first = 1
        if p[0] == "*":
            while len(p) > first and p[first] == "*":
                f[0][first] = True
                first = first + 1
            if len(p) > first and (s[0] == p[first] or p[first] == "?"):
                f[0][first] = True
        for i in range(0, len(s)):
            for j in range(0, len(p)):
                if i > 0 and p[j] == "*":
                    f[i][j] |= f[i - 1][j]
                if p[j] == "*" and i > 0 and j > 0:
                    f[i][j] |= f[i - 1][j - 1]
                if p[j] == "*" and j > 0:
                    f[i][j] |= f[i][j - 1]
                if (s[i] == p[j] or p[j] == "?") and i > 0 and j > 0:
                    f[i][j] |= f[i - 1][j - 1]
        return f[-1][-1]


if __name__ == '__main__':
    s = "mississippi"
    p = "*"
    print(Solution().isMatch(s, p))
