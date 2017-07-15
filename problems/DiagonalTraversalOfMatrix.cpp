#include "leetcode.h"
/**
Zigzag (or diagonal) traversal of Matrix

    1     2     3     4
    5     6     7     8
    9    10    11    12
   13    14    15    16
   17    18    19    20
 ------------------------>
    1
    5     2
    9     6     3
   13    10     7     4
   17    14    11     8
   18    15    12
   19    16
   20

https://www.careercup.com/question?id=5163286157852672
http://www.geeksforgeeks.org/zigzag-or-diagonal-traversal-of-matrix/
*/

class Solution {
public:
    vector<vector<int>> diagonalOrder(vector<vector<int>>& matrix){
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ret(n + m - 1);
        for(int k = 0; k < ret.size(); k++){
            int i = k < n ? k : n - 1;
            while(i >= 0 && k - i >= 0 && k - i < m){
                ret[k].push_back(matrix[i][k - i]);
                i--;
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};
    auto ans = s1.diagonalOrder(matrix);
    show(ans);
}
