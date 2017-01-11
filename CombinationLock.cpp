/*
ID: crazyco3
PROG: combo
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

ifstream fin ("combo.in");
ofstream fout ("combo.out");

void show(vector<vector<int>> t){
    for(auto tt : t){
        for(auto ttt: tt)
            cout << ttt << "  ";
    cout << endl;
    }

}


int main() {

    // 1. input lock
    int n, tmp;
    fin >> n;
    vector<int> farmer(3);
    vector<int> master(3);
    for(int i=0;i<3;i++){
        fin >> tmp;
        farmer[i] = tmp - 1;
    }
    for(int i=0;i<3;i++){
        fin >> tmp;
        master[i] = tmp - 1;
    }

    // 2. calculate valid number by small tolerance
    vector<vector<int>> validFarmerNum(3, vector<int> (5));
    vector<vector<int>> validMasterNum(3, vector<int> (5));
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            validFarmerNum[i][j] = (farmer[i] + j - 2 + n)%n;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            validMasterNum[i][j] = (master[i] + j - 2 + n)%n;
        }
    }

    // 3. calculate combo's hash value
    vector<int> result;
    int hashValue;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                hashValue = 10000*validFarmerNum[0][i] + 100 * validFarmerNum[1][j] + validFarmerNum[2][k];
                result.push_back(hashValue);
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                hashValue = 10000*validMasterNum[0][i] + 100 * validMasterNum[1][j] + validMasterNum[2][k];
                result.push_back(hashValue);
            }
        }
    }
    // 4. how to unique a duplicated vector {sort, unique, erase}
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    fout << result.size() << endl;

    return 0;
}
