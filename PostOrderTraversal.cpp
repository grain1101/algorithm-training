#include "leetcode.h"
/**
Tree PostOrder Traversal
 */


class Solution {
public:
    // Recursive
    vector<int> postOrderTraversalRecursive(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        vector<int> left = postOrderTraversalRecursive(root->left);
        vector<int> right = postOrderTraversalRecursive(root->right);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        ret.insert(ret.end(), root->val);
        return ret;
    }
    // Iterative
    vector<int> postOrderTraversalIterative(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        stack<TreeNode*> st;
        TreeNode *cur, *prev;
        st.push(root);
        while(!st.empty()){
            cur = st.top();
            if (prev == nullptr || prev->left == cur || prev->right == cur){ // traverse down the tree

                if (!cur->left)         st.push(cur->left);
                else if (!cur->right)   st.push(cur->right);
            } else if (cur->left == prev) {     // traverse up the tree from the left
                if (!cur->right) st.push(cur->right);
            } else {            // traverse up the tree from the right
                ret.push_back(cur->val);
                st.pop();
            }
            prev = cur;
        }
        return ret;
    }
};

int main() {
    Solution s1;
    TreeNode* root = new TreeNode(1);
    auto ret = s1.postOrderTraversalIterative(root);
    showV(ret);
}
