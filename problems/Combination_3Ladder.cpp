#include "leetcode.h"
/**
If you can hop 1, 2, or 3 steps at a time, calculate the total number of possible combinations for `n` steps.

https://www.careercup.com/question?id=5642960319283200
*/

class Solution {
public:
    int combination(int n){
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

int main() {
    Solution s1;
    int n = 3;
    auto ans = s1.combination(n);
    cout << ans << endl;
}
