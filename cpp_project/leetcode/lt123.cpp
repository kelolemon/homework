//
// Created by 邓萌达 on 12/6/20.
//
# include <vector>
# include <iostream>
# include <cstdio>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int first[2];
        int second[2];
        first[0] = -prices[0];
        first[1] = -23333333;
        second[0] = -2333333;
        second[1] = -2333333;
        for (int i = 1; i < prices.size(); i++) {
            first[0] = max(first[0], -prices[i]);
            first[1] = max(first[1], prices[i] + first[0]);
            second[0] = max(second[0], first[1] - prices[i]);
            second[1] = max(second[1], prices[i] + second[0]);
        }
        return max(0, max(first[1], second[1]));
    }
};

