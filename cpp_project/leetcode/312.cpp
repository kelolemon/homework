//
// Created by 邓萌达 on 23/6/20.
//

# include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int f[n + 2][n + 2];
        memset(f, 0, sizeof(f));
        for (int len = 0; len < n; len++) {
            for (int i = 1; i <= n; i++) {
                if (i + len > n) break;
                for (int k = 0; k <= len; k++) {
                    int sub = f[i][i + k - 1] + f[i + k + 1][i + len] +
                              nums[i - 1] * nums[i + len + 1] * nums[i + k];
                    if (sub > f[i][i + len]) {
                        f[i][i + len] = sub;
                    }
                }
            }
        }
        return f[1][n];
    }
};