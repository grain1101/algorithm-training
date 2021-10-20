class Solution {
 public:
  int countMaxOrSubsets(vector<int> &a) {
    int t = 0;
    int n = a.size();
    int ret = 0;
    for (auto x : a) t |= x;
    for (int k = 1; k < (1<<n); k++) {
      int b = 0;
      for(int i = 0; i < n; i++) {
        if (k & (1<<i)) b |= a[i];
      }
      if (b == t) ret++;
    }
    return ret;
  }
};
