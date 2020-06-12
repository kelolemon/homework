//
// Created by 邓萌达 on 12/6/20.
//
# include <cstring>
# include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string target;
        for (char i : s) {
            if (i >= '0' && i <= '9') {
                target += i;
            }
            if (i >= 'a' && i <= 'z') {
                target += i;
            }
        }
        if (target.empty()) {
            return true;
        }
        for (int i = 0; i < target.length() / 2 + 1; i++) {
            if (target[i] != target[target.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};