class Solution {
 public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> idx1;
    vector<int> ret(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++) {
      idx1[nums1[i]] = i;
    }
    stack<int> st;
    for (int i = 0; i < nums2.size(); i++) {
      while (!st.empty() && nums1[st.top()] < nums2[i]) {
        ret[st.top()] = nums2[i];
        st.pop();
      }
      auto it = idx1.find(nums2[i]);
      if (it != idx1.end()) {
        st.push(it->second);
      }
    }
    return ret;
  }
};
