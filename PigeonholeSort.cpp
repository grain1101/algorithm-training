class PigeonholeSort {
public:
    void pigeonholeSort(vector<int>& nums) {
		int maxV = *max_element(nums.begin(), nums.end());
		int minV = *min_element(nums.begin(), nums.end());
		int len = maxV - minV + 1;
		vector<vector<int>> hole(len);
		for(auto n : nums) {
			hole[n - minV].push_back(n);	// offset is minV;
		}
		int idx = 0;
		for(int i = 0; i < len; i++) {
			for(auto n : hole[i]) {
				nums[idx++] = n;
			}
		}
	}
};