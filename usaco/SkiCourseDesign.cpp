/*
ID: crazyco3
PROG: skidesign
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <limits.h>

using namespace std;
typedef pair<int, int> PII;

ifstream fin ("skidesign.in");
ofstream fout ("skidesign.out");

int result = INT_MAX;
vector<PII> point;
const int heigh = 17;

void show(const vector<PII>& v){
    for(auto& vv : v){
            cout << vv.first << "\t" << vv.second;
    cout << endl;
    }

}

int square(int x){
    return x*x;
}

int main() {

    // 0. input lock
    int n;
    fin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        fin >> nums[i];
    }

    for(int i=1;i<=100;i++){
        int tmp = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] < i ){
                tmp += square(i-nums[j]);
            }
            if(nums[j] > i+17){
               tmp += square(nums[j]-i-17);
            }

        }
         result = min(result, tmp);
    }

    fout << result << endl;

    return 0;
}
