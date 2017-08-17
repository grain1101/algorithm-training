#include "leetcode.h"
/**
LCA
FirstCommonAncestor

https://www.careercup.com/question?id=5631912925200384
https://leetcode.com/problemset/algorithms/?search=ancestor
*/

class Solution {
public:
    TreeNode* LCABST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p && !q) return p;
        if (!p || !q) return p== nullptr? q : p;
        if (q->val < p->val) return LCABST(root, q, p);
        if (p->val < root->val && q->val < root->val) return LCABST(root->left, p, q);
        if (p->val > root->val && q->val > root->val) return LCABST(root->right, p, q);
        return root;
    }
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || !p && !q) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if (left){
            if (right) return root;
            return left;
        }
        return right;
        //return left ? (right ? root : left)  : right;
    }
};

int main() {
    Solution s1;
    int n = 3;
    auto ans = s1.combination(n);
    cout << ans << endl;
}
