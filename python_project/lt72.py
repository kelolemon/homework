class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        n = len(word1)
        m = len(word2)
        f = [[0] * m for _ in range(n)]
        f[0][0] = 0 if word1[0] == word2[0] else 1
        for i in range(1, n):
            if word1[i] == word2[0]:
                f[i][0] = i
            else:
                f[i][0] = f[i - 1][0] + 1
        for i in range(1, m):
            if word1[0] == word2[i]:
                f[0][i] = i
            else:
                f[0][i] = f[0][i - 1] + 1
        for i in range(1, n):
            for j in range(1, m):
                if word1[i] == word2[j]:
                    f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1, f[i - 1][j - 1])
                else:
                    f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1, f[i - 1][j - 1] + 1)
        return f[-1][-1]


if __name__ == '__main__':
    word1 = "a"
    word2 = "ab"
    print(Solution().minDistance(word1, word2))
