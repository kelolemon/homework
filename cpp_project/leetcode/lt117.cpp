//
// Created by kelo on 2020/4/27.
//

class Solution {
public:
    void dfs(Node* x) {
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
        dfs(x->right);
        dfs(x->left);
    }

    Node* connect(Node* root) {
        this->dfs(root);
        return root;
    }
};