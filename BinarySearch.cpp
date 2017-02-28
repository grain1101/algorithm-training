int binarySearch_any(vector<int>& nums, int target, bool isFirst/*left:True right:False*/){
    std::function<bool(int)> isLeftPart = isFirst ?
        [](int idx) { return nums[idx] < target} :
        [](int idx) { return nums[idx] <= target};
    if (nums.size() == 0) return -1;
    int l = 0;
    int r = nums.size() - 1;
    if (isLeftPart(r)) {
        if (isFirst) return -1;
        return nums[r] == target ? r : -1;
    }
    if (!isLeftPart(l)) {
        if (isFirst) return nums[l] == target ? l : -1;
        return -1;
    }
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (isLeftPart(mid)) l = mid;
        else r = mid;
    }
    if (isFirst) return nums[r] == target ? r : -1;
    return nums[l] == target ? l : -1;
}

bool isLeftPart(int idx) {
    return d[idx] <= 3;
}
int solve() {
    int l = binarySearch();
    return l + 1;
}
int binarySearch() {
    int l = 0;
    int r = n - 1;
    if (isLeftPart(r)) return r; // the full range is in the left part
    if (!isLeftPart(l)) return -1; // the full range is in the right part
    while(l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (isLeftPart(mid)) l = mid;
        else r = mid;
    }
    return l;
}