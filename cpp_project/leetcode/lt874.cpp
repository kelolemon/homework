class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> obstacles_x[60001];
        vector<int> obstacles_y[60001];
        for (int i = 0; i < obstacles.size(); i++) {
            obstacles_x[obstacles[i][1] + 30000].push_back(obstacles[i][0]);
            obstacles_y[obstacles[i][0] + 30000].push_back(obstacles[i][1]);
        }
        for (int i = 0; i <= 60000; i++) {
            sort(obstacles_x[i].begin(), obstacles_x[i].end());
            sort(obstacles_y[i].begin(), obstacles_y[i].end());
        }
        int bot_x = 0;
        int bot_y = 0;
        int step = 0;
        int ans = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                step = (step + 1) % 4;
                continue;
            }
            if (commands[i] == -2) {
                step = (step + 3) % 4;
                continue;
            }
            if (step == 0) {
                int find_x = bot_x + 30000;
                if (obstacles_y[find_x].size() == 0) {
                    bot_y += commands[i];
                } else {
                    vector<int>::iterator iterator = upper_bound(obstacles_y[find_x].begin(), obstacles_y[find_x].end(), bot_y);
                    if (iterator != obstacles_y[find_x].end() && bot_y + commands[i] >= *iterator) {
                        bot_y = (*iterator) - 1;
                    } else {
                        bot_y += commands[i];
                    }
                }
            }
            if (step == 1) {
                int find_y = bot_y + 30000;
                if (obstacles_x[find_y].size() == 0) {
                    bot_x += commands[i];
                    printf("%d %d===\n", bot_x, bot_y);
                } else {
                    vector<int>::iterator iterator = upper_bound(obstacles_x[find_y].begin(), obstacles_x[find_y].end(), bot_x);
                    if (iterator != obstacles_x[find_y].end() && bot_x + commands[i] >= *iterator) {
                        bot_x = (*iterator) -1;
                    } else {
                        bot_x += commands[i];
                    }
                }
            }
            if (step == 2) {
                int find_x = bot_x + 30000;
                if (obstacles_y[find_x].size() == 0) {
                    bot_y -= commands[i];
                } else {
                    vector<int>::iterator iterator = lower_bound(obstacles_y[find_x].begin(), obstacles_y[find_x].end(), bot_y);
                    if (iterator != obstacles_y[find_x].begin() && bot_y - commands[i] <= *(iterator - 1)) {
                        bot_y = (*(iterator - 1)) + 1;
                    } else {
                        bot_y -= commands[i];
                    }
                }
            }
            if (step == 3) {
                int find_y = bot_y + 30000;
                if (obstacles_x[find_y].size() == 0) {
                    bot_x -= commands[i];
                } else {
                    vector<int>::iterator iterator = lower_bound(obstacles_x[find_y].begin(), obstacles_x[find_y].end(), bot_x);
                    if (iterator != obstacles_x[find_y].begin() && bot_x - commands[i] <= *(iterator - 1)) {
                        bot_x = (*(iterator - 1)) + 1;
                    } else {
                        bot_x -= commands[i];
                    }
                }
            }
            printf("%d\n", step);
            printf("%d %d\n", bot_x, bot_y);
            ans = max(ans, bot_x * bot_x + bot_y * bot_y);
        }
        return ans;
    }
};