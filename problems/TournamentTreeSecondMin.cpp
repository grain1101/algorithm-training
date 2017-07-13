#include "leetcode.h"
/*
Tournament Tree
A tournament tree is a binary tree, where the parent is the minimum of the two children.
* Given a tournament tree find the second minimum value in the tree.
* A node in the tree will always have 2 or 0 children.
* Also all leaves will have distinct and unique values.

https://www.careercup.com/question?id=5196022759292928
*/

typedef pair<int, int> PII;
class Solution {
public:
    int secondMin(TreeNode* root){
        if (!root->left && !root->right) return root->val;
        int cur = root->val;
        int left = root->left->val > cur ? root->left->val : secondMin(root->left);
        int right = root->right->val > cur ? root->right->val : secondMin(root->right);
        left = (left == cur) ? INT_MAX : left;
        right = (right == cur) ? INT_MAX : right;
        return min(left, right);
    }
};

int main() {
    Solution s1;
    vector<int> nodes= {2,2,3,4,2,5,3};

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(3);
    cout << s1.secondMin(root) << endl;
}
