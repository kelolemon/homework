//
// Created by 邓萌达 on 13/6/20.
//

# include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int ans = 0;
    void dfs (TreeNode* x, int sub_ans) {
        if (x == nullptr) {
            return;
        }
        if (x->left == nullptr && x->right == nullptr) {
            this->ans += sub_ans * 10 + x->val;
            return;
        }
        dfs(x->left, sub_ans * 10 + x->val);
        dfs(x->right, sub_ans * 10 + x->val);
    }
    int sumNumbers(TreeNode* root) {
        this->ans = 0;
        this->dfs(root, 0);
        return this->ans;
    }
};