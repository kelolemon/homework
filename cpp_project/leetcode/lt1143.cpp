//
// Created by 邓萌达 on 24/6/20.
//

# include "string"
# include <iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if (n == 0 || m == 0) {
            return 0;
        }
        int f[n][m];
        memset(f, 0, sizeof(f));
        f[0][0] = text1[0] == text2[0];
        for (int i = 1; i < n; i++) {
            if (text1[i] == text2[0]) f[i][0] = 1;
            else f[i][0] = f[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            if (text2[i] == text1[0]) f[0][i] = 1;
            else f[0][i] = f[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (text1[i] == text2[j]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
                }
                f[i][j] = max(f[i][j], max(f[i - 1][j], max(f[i][j - 1], f[i - 1][j - 1])));
            }
        }
        return f[n - 1][m - 1];
    }
};

int main() {
    Solution test;
    cout << test.longestCommonSubsequence("ezupkr", "ubmrapg") << endl;
}