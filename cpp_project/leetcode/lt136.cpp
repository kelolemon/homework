//
// Created by 邓萌达 on 13/6/20.
//
# include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int ans = 0;
        for (int num : nums) {
            ans ^= (unsigned )num;
        }
        return (int)ans;
    }
};