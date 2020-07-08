//
// Created by 邓萌达 on 8/7/20.
//
# include <string>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int steps = 0;
        pair<int, int> locate;
        locate.first = 0;
        locate.second = 0;
        steps = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (auto command : instructions) {
            if (command == 'L') steps += 1;
            if (command == 'R') steps -= 1;
            if (command == 'G') {
                locate.first += dx[steps];
                locate.second += dy[steps];
            }
            steps += 4;
            steps %= 4;
        }
        return (locate.first == 0 && locate.second == 0) || steps != 0;
    }
};
