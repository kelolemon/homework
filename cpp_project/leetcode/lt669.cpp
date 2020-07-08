//
// Created by 邓萌达 on 8/7/20.
//


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
    TreeNode *dfs(TreeNode *x, int L, int R) {
        if (x == nullptr) {
            return nullptr;
        }
        if (x->val > R) return dfs(x->left, L, R);
        if (x->val < L) return dfs(x->right, L, R);
        x->left = dfs(x->left, L, R);
        x->right = dfs(x->right, L, R);
        return x;
    }

    TreeNode *trimBST(TreeNode *root, int L, int R) {
        return dfs(root, L, R);
    }
};