//
// Created by 邓萌达 on 22/6/20.
//
# include <cmath>
# include <algorithm>
# include <iostream>

class Solution {
public:
    int f[101][10001];
    int mid_search(unsigned int left, unsigned int right, const int n, const int k) {
        if (left + 1 >= right) {
            return (int )left;
        }
        int mid = (int ) ((left + right) >> 1u);
        int cnt = this->f[k - 1][mid - 1] - this->f[k][n - mid];
        if (cnt == 0) {
            return mid;
        }
        if (cnt > 0) {
            return mid_search(left, mid, n, k);
        } else return mid_search(mid, right, n, k);
    }

    int superEggDrop(int K, int N) {
        memset(this->f, 0, sizeof(this->f));
        if (K == 0) {
            return 233333333;
        }
        for (int i = 1; i <= N; i++) this->f[1][i] = i;
        for (int i = 1; i <= K; i++) this->f[i][1] = 1;
        for (int i = 2; i <= K; i++) {
            for (int j = 2; j <= N; j++) {
                int left = 1;
                int right = j - 1;
                int k = this->mid_search(left, right,j, i);
                if (k + 1 <= N)
                    this->f[i][j] = std::min(std::max(this->f[i - 1][k - 1], this->f[i][j - k]),
                                            std::max(this->f[i - 1][k], this->f[i][j - k - 1])) + 1;
                else
                    this->f[i][j] = std::max(this->f[i - 1][k - 1], this->f[i][j - k]) + 1;
            }
        }
        return this->f[K][N];
    }
};

int main() {
    int k = 3, n = 14;
    Solution test;
    std::cout << test.superEggDrop(k, n) << std::endl;
    return 0;
}