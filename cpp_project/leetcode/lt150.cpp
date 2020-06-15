//
// Created by 邓萌达 on 14/6/20.
//

# include "vector"
# include "string"
# include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& str : tokens) {
            if (str == "*") {
                int x  = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x * y);
            }
            if (str == "/") {
                int x  = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x / y);
            }
            if (str == "+") {
                int x  = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x + y);
            }
            if (str == "-") {
                int x  = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x - y);
            }
            if (all_of(str.begin(), str.end(), ::isdigit)) {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};