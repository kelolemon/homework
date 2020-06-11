//
// Created by kelo on 2020/4/27.
//

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void dfs(Node* x, bool IsLeftMost) {
        if (x == nullptr) {
            return;
        }
        if (x->left) {
            if (x->right) {
                x->left->next = x->right;
            } else {
                Node *t = x;
                while (t->next && t->next->left == nullptr && t->next->right == nullptr) {
                    t = t->next;
                }
                if (t->next && t->next->left) {
                    x->left->next = t->next->left;
                } else {
                    if (t->next && t->next->right) {
                        x->left->next = t->next->right;
                    }
                }
            }
        }

        if (x->next && x->right) {
            Node *t = x;
            while (t->next && t->next->left == nullptr && t->next->right == nullptr) {
                t = t->next;
            }
            if (t->next && t->next->left) {
                x->right->next = t->next->left;
            } else {
                if (t->next && t->next->right) {
                    x->right->next = t->next->right;
                }
            }
        }
        dfs(x->next, false);
        if (IsLeftMost) {
            if (x->left) dfs(x->left, true);
            else dfs(x->right, true)
        }
    }

    Node* connect(Node* root) {
        this->dfs(root, true);
        return root;
    }
};