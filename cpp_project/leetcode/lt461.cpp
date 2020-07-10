//
// Created by 邓萌达 on 10/7/20.
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        int sub_ans = x ^ y;
        int ans = 0;
        while (sub_ans) {
            ans += sub_ans & 1;
            sub_ans >>= 1;
        }
        return ans;
    }
};