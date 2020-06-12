//
// Created by 邓萌达 on 12/6/20.
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
    int ans = -2333333;
    int dfs(TreeNode* x) {
        if (x == nullptr) {
            return -2333333;
        }
        int left_max = dfs(x->left);
        int right_max = dfs(x->right);
        ans = max(ans, max(x->val, max(left_max + x->val, right_max + x->val)));
        ans = max(ans, x->val + left_max + right_max);
        return max(x->val, max(x->val + left_max, x->val + right_max));
    }

    int maxPathSum(TreeNode* root) {
        this->ans = -23333333;
        dfs(root);
        return ans;
    }
};
