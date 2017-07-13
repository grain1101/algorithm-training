/*
ID: crazyco3
PROG: sprime
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
#include <cstdlib>

#define Max_Upper 10000

using namespace std;
typedef pair<int, int> PII;
vector<int> result;
vector<vector<int>> superPrime(9);

bool isPrime(int n){
    int sqrtn = sqrt(n);
    for(int i=2;i<=sqrtn;i++){
        if(n%i==0) return false;
    }
    return true;
}

void Solve(int n){
    if(n==1) return;
    for(int loop = 1;loop<n;loop++){
        for(int i=0;i<superPrime[loop].size();i++){
            for(int j=0;j<=9;j++){
                int tmp = superPrime[loop][i] * 10 + j;
                if(isPrime(tmp)) superPrime[loop+1].push_back(tmp);
            }
        }
    }
}

int main() {
    ifstream fin ("sprime.in");
    int n;
    fin >> n;
    fin.close();
    superPrime[1] = {2,3,5,7};

    Solve(n);
    ofstream fout ("sprime.out");
    sort(superPrime[n].begin(), superPrime[n].end());
    for(int i=0;i<superPrime[n].size();i++){
        fout << superPrime[n][i] << endl;
    }
    fout.close();
    return 0;
}
