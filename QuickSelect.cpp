#include "C:\Users\grain\Desktop\gitrepo\Test\leetcode.h"
/**
QuickSelect:
The QuickSelect algorithm quickly finds the k-th smallest element of an unsorted array of n elements.
Average - O(n)
Worst case - O(n**2)
1. partition (pivot)
2. select
**/
class QuickSelect {
public:
//    vector<int> topKthSmallestElements(vector<int>& nums, int k) {
//        if (nums.size() <= k) return nums;
//        return quickSelect(nums, 0, nums.size() - 1, k);
//    }
//    vector<int> topKthLargestElements(vector<int>& nums, int k) {
//    }
    int findKthLargestElement(vector<int>& nums, int k) {
        return findKthSmallestElement(nums, nums.size() + 1 - k);
    }
    int findKthSmallestElement(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
private:
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int pivot = partitions(nums, l, r);
        int len = pivot - l + 1;
        if (len == k) return nums[pivot];
        else if (len > k) return quickSelect(nums, l, pivot - 1, k);
        else return quickSelect(nums, pivot + 1, r, k - len);
    }
    int partitions(vector<int>& nums, int l, int r) {
        swap(nums[rand() % (r - l + 1) + l], nums[r]);
        int pivot = nums[r];
        while(l < r) {
            while (l < r && nums[l] < pivot) l++;
            while (r > l && nums[r] > pivot) r--;
            if (nums[l] == nums[r]) l++;
            else swap(nums[l], nums[r]);
        }
        return r;
    }
    void quick_select_ZZZ(vector<int>& num, int l, int r, int k) {
        //cout << "l = " << l << ", r = " << r << ", k = " << k << endl;
        //for(int x = l; x <= r; x++) cout << num[x] << " "; cout << endl;
        int len = r - l + 1;
        //assert(k >= 0 && k <= r - l + 1);
        if (l >= r || k <= 0 || k >= len) return;
        swap(num[rand() % len + l], num[r]);
        int s = l;
        int e = r - 1;
        while(s < e) {
            while(s < e && num[s] < num[r]) s++;
            while(s < e && num[r] <= num[e]) e--;
            if (s < e) swap(num[s], num[e]);
        }
        if(num[e] < num[r]) e++;
        int nleft = e - l;
        if (k < nleft) quick_select_ZZZ(num, l, e - 1, k);
        else quick_select_ZZZ(num, e, r, k - nleft);
    }
};
int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    QuickSelect q;
    showL(q.findKthSmallestElement(nums, 5));
    showV(nums);
    sort(nums.begin(), nums.end());
    showV(nums);
}
