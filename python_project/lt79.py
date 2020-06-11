from typing import List


class Solution:
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    ans = False

    def search(self, step, k, n, m, v, i, j, board, word):
        if step == k:
            self.ans = True
            return
        if self.ans:
            return
        for x in range(4):
            i = i + self.dx[x]
            j = j + self.dy[x]
            if i < 0 or j < 0 or i >= n or j >= m or v[i][j]:
                i = i - self.dx[x]
                j = j - self.dy[x]
                continue
            if board[i][j] == word[step]:
                v[i][j] = True
                self.search(step + 1, k, n, m, v, i, j, board, word)
                v[i][j] = False
            i = i - self.dx[x]
            j = j - self.dy[x]

    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        if n == 0:
            return False
        m = len(board[0])
        k = len(word)
        v = [[False] * m for _ in range(n)]
        if m == 0:
            return False
        if not word:
            return True
        for i in range(0, n):
            for j in range(0, m):
                if board[i][j] == word[0]:
                    v[i][j] = True
                    self.search(1, k, n, m, v, i, j, board, word)
                    v[i][j] = False
                    if self.ans:
                        return True
        return False


if __name__ == '__main__':
    board = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
    word = "ASADFBCCEESE"
    print(Solution().exist(board, word))
