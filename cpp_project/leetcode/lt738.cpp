//
// Created by 邓萌达 on 10/7/20.
//

# include <vector>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> digit;
        int x = N;
        for (;x;) {
            digit.push_back(x % 10);
            x /= 10;
        }
        int remark = 0;
        for (int i = 0; i < digit.size() - 1; i++) {
            if (digit[i] < digit[i + 1]) {
                remark = i + 1;
                digit[i + 1] -= 1;
            }
        }
        for (int i = 0; i < remark; i++) {
            digit[i] = 9;
        }
        reverse(digit.begin(), digit.end());
        int ans = 0;
        for (int i : digit) {
            ans *= 10;
            ans += i;
        }
        return ans;
    }
};

int main() {
    Solution a;
    int ans = a.monotoneIncreasingDigits(332);
    printf("%d \n", ans);
}