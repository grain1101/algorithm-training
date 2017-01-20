#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>


using namespace std;

class Solution {
public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        // 1. Two Sum
//        vector<int> result;
//        unordered_map<int,int> mapping;
//        for(int i=0;i<nums.size();i++){
//            if(mapping.find(target - nums[i]) == mapping.end()){
//                mapping[i] = nums[i];
//            }
//            else{
//                return vector<int>{mapping}
//            }
//        }
//        return result;
//    }
};
void inplace_swap(int& a, int& b){
    b = a^b;
    a = a^b;
    b = a^b;
}
int strlonger(char *a, char *b){
    cout << strlen(a) - strlen(b) << endl;
    return strlen(a) - strlen(b) > 0;
}
int main()
{

//    Solution s1;
//    s1.twoSum();


    char *a, *b;
    a = "";
    b = "b";
    strlonger(a,b);
//    cout << strlonger(a,b) << endl;;
    return 0;
}
