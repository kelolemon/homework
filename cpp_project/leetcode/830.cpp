//
// Created by 邓萌达 on 13/6/20.
//
# include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        ans.clear();
        if (S.empty()) {
            return ans;
        }
        for (int i = 0; i < S.length(); i++) {
            int x = i;
            while (S[x] == S[x + 1]) x = x + 1;
            if (x - i + 1 >= 3) {
                vector<int> sub_ans;
                sub_ans.push_back(i);
                sub_ans.push_back(x);
                ans.push_back(sub_ans);
            }
        }
        return ans;
    }
};