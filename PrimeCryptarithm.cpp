/*
ID: crazyco3
PROG: crypt1
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
vector<int> nums;
ifstream fin ("crypt1.in");
ofstream fout ("crypt1.out");

void show(set<int> t){
    for(auto tt : t){
        cout << tt << "  ";
    }
    cout << endl;
}

int multiple(const int a, const int b, const int c, const int d){
    int multiplicand = 100*a+10*b+c;
    return multiplicand * d;
}

bool check(int value){
    //if(value > 999 || value < 100) return false;
    int flag = 0;
    int cnt = 0;
    while(value){
        cnt++;
        int tmp = value%10;
        for(int i=0;i<nums.size();i++){
            if(tmp == nums[i]) flag++;
        }
        value /= 10;
    }
    return (flag == cnt);
}

bool check3digitsLen(int n){
    return n>=100 && n<=999;
}
bool check4digitsLen(int n){
    return n>=1000 && n<=9999;
}

int main() {

    int n;
    fin >> n;
    int tmp;
    vector<int> result;
    for(int i=0;i<n;i++){
        fin >> tmp;
        nums.push_back(tmp);
    }

    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                for(int d=0;d<n;d++){
                    for(int e=0;e<n;e++){
                        int product1 = multiple(nums[a], nums[b], nums[c], nums[d]);
                        int product2 = multiple(nums[a], nums[b], nums[c], nums[e]);
                        int tmp = product2 + 10 * product1;
                        if(check3digitsLen(product1) && check3digitsLen(product2) && check4digitsLen(tmp)  &&
                           check(product1) && check(product2) && check(tmp)){
                                result.push_back(tmp);
                                cout <<"abc:"<<nums[a]<<nums[b]<<nums[c]<<" de:" <<nums[d]<<nums[e]<<" product1:"<<product1<<" product2:"<<product2<<" tmp:"<<tmp <<endl;
                           }
                    }
                }
            }
        }
    }

    //show(result);
    //cout << result.size() << endl;
    fout << result.size() << endl;

    return 0;
}
