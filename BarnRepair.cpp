/*
ID: crazyco3
PROG: barn1
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

using namespace std;
typedef pair<int, int> PII;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

void show(vector<int> t){
    for(auto tt : t){
        cout << tt << "  ";
    }
    cout << endl;
}

int findMaxnumber(const vector<int>& nums){
    int num = 0;
    int subscript = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > num){
            num = nums[i];
            subscript = i;
        }
    }
    return subscript;
}

int main() {

    int m, s, c;
    fin >> m >> s >> c;
    int result = 0;
    // 1. input stalls numbers
    vector<int> stalls;
    int tmp;
    for(int i=0;i<c;i++){
        fin >> tmp;
        stalls.push_back(tmp);
    }
    sort(stalls.begin(), stalls.end());

    // 2. calculate the discontinuous segments
    vector<int> segments(c, 0);
    for(int i=1;i<c;i++){
        segments[i] = stalls[i]-stalls[i-1]-1;
    }

    // 3. find m-1 max discontinuous segments subscript
    vector<int> subscripts;
    for(int i=0;i<m-1;i++){
        int tmp = findMaxnumber(segments);
        if(tmp == 0) break;
        subscripts.push_back(tmp);
        segments[tmp] = 0;
    }
    sort(subscripts.begin(), subscripts.end());

    // 4. calculate stalls
    int p,q;
    p = 0;
    for(int i=0;i<=subscripts.size();i++){
        if(i==subscripts.size()){
            q = stalls.size();
        }
        else{
            q = subscripts[i];
        }
        result += stalls[q-1] - stalls[p] + 1;
        p = q;
    }
    fout << result << endl;

    return 0;
}
