//
// Created by 邓萌达 on 26/6/20.
//

# include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        if (n == 1) {
            return true;
        }
        int f[n][n];
        int g[n][n];
        for (int i = 0; i < n; i++) {
            f[i][i] = piles[i];
            g[i][i] = piles[i];
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = i + len;
                if (j >= n) break;
                g[i][j] = g[i][j - 1] + piles[j];
                int max_left = max(f[i + 1][j], g[i + 1][j] - f[i + 1][j] + piles[i]);
                int max_right = max(f[i][j - 1], g[i][j - 1] - f[i][j - 1] + piles[j]);
                f[i][j] = max(max_left, max_right);
            }
        }
        return 2 * f[0][n - 1] > g[0][n - 1];
    }
};