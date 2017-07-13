/*
ID: crazyco3
PROG: pprime
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

int isPalindrome[Max_Upper];
vector<int> result;

vector<int> numToVector(int n){
    vector<int> num;
    while(n){
        num.push_back(n%10);
        n /= 10;
    }
    return num;
}

bool isPrime(int a){
    int sqrta = sqrt(a);
    for(int i=2;i<=sqrta;i++){
        if(a%i==0) return false;
    }
    return true;
}

int mirror(int n, int flag){
    // mirror: (n) abc-> abcba
    vector<int> num;
    num = numToVector(n);
    int len = num.size();
    int nn[len*2];
    int np=0;
    for(int i=len-1;i>=0;i--){
        nn[np++] = num[i];
    }
    for(int i=flag;i<len;i++){
        nn[np++] = num[i];
    }
    int result = 0;
    for(int i=0;i<np;i++){
        result = result*10 + nn[i];
    }
    return result;
}
enum mirrorFlag{
    even,
    odd
};

int main() {
    ifstream fin ("pprime.in");
    int a, b; // [a, b] -> // [5, 100000000]
    fin >> a >> b;
    fin.close();

    int bSize = numToVector(b).size();
    int len = 1;
    for(int i=0;i<(bSize+1)/2;i++){
        len *=10;
    }
    for(int i=1;i<len;i++){
        int tmpA = mirror(i, mirrorFlag::odd); // odd: abcba
        if(a<=tmpA && tmpA <=b && isPrime(tmpA)){
            //cout << "i:" << i << "mirrorA:" << tmpA << endl;
            result.push_back(tmpA);
        }

        int tmpB = mirror(i,mirrorFlag::even);
        if(a<=tmpB && tmpB <=b && isPrime(tmpB)){
            result.push_back(tmpB);
        }
    }
    sort(result.begin(), result.end());
    ofstream fout ("pprime.out");
    for(int i=0;i<result.size();i++){
        fout << result[i] << endl;
    }
    fout.close();
    return 0;
}
