 /*
 // Amazon
    //    1
    //  /    \
    // 2      20
//    /  \   /  \
//   3    4 /    \
    //     /      \
    //    5        7
// [3, 2, 10, 20,7]
1. how to get the tree's max width?
    use BFS. maxWidth = max(maxWidth, q.size());
*/
class VerticalSum{
public:
    vector<int> verticalSum(TreeNode* root) {
        vector<int> ret;
        unordered_map<int, int> m;
        int minV = INT_MAX, maxV = INT_MIN;
        getVertical(root, m, 0, minV, maxV);
        ret.assign(maxV + abs(minV) + 1, 0);
        for(auto it= m.begin(); it!=m.end(); it++) {
            ret[it->first + minV] = it->second;
        }
        return ret;
    }
    void getVertical(TreeNode* root, unordered_map<int, int>& m, int col, int& minV, int&maxV) {
        if (!root) return;
        m[col] += root->val;
        maxV = max(maxV, col);
        minV = min(minV, col);
        getVertical(root->left,  m, col - 1, minV, maxV);
        getVertical(root->right, m, col + 1, minV, maxV);
    }
};