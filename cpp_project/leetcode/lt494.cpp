//
// Created by 邓萌达 on 9/7/20.
//

# include <vector>

using namespace std;

class Solution {
public:

    void dfs_left(int step, vector<int> nums, int tot) {
        if (step == nums.size()) {
            this->left_ans.push_back(tot);
            return;
        }
        // minus
        dfs_left(step + 1, nums, tot - nums[step]);
        // plus
        dfs_left(step + 1, nums, tot + nums[step]);
    }

    void dfs_right(int step, vector<int> nums, int tot) {
        if (step == nums.size()) {
            this->right_ans.push_back(tot);
            return;
        }
        // minus
        dfs_right(step + 1, nums, tot - nums[step]);
        // plus
        dfs_right(step + 1, nums, tot + nums[step]);
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        this->ans = 0;
        this->left.clear();
        this->right.clear();
        this->left_ans.clear();
        this->right_ans.clear();
        for (int i = 0; i < nums.size(); i++) {
            if (i > nums.size() / 2) this->right.push_back(nums[i]);
            else this->left.push_back(nums[i]);
        }
        dfs_left(0, this->left, 0);
        dfs_right(0, this->right, 0);
        sort(this->left_ans.begin(), this->left_ans.end());
        sort(this->right_ans.begin(), this->right_ans.end());
        for (int x : left_ans) {
            long long y = (long long )S - (long long )x;
            int lft = lower_bound(right_ans.begin(), right_ans.end(), y) - right_ans.begin();
            int rgt = upper_bound(right_ans.begin(), right_ans.end(), y) - right_ans.begin();
            this->ans += (rgt - lft);

        }
        return this->ans;
    }

private:
    int ans;
    vector<int> left;
    vector<int> right;
    vector<int> left_ans;
    vector<int> right_ans;
};