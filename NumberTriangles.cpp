/*
ID: crazyco3
PROG: numtri
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


int main() {
    ifstream fin ("numtri.in");
    int n;
    fin >> n;
    vector<vector<int>> numtri(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int tmp;
            fin >> tmp;
            numtri[i].push_back(tmp);
        }
    }
    fin.close();

    for(int i=1;i<n;i++){
        numtri[i][0] +=numtri[i-1][0];
    }
    for(int i=1;i<n;i++){
        numtri[i][i] += numtri[i-1][i-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
            numtri[i][j] += max(numtri[i-1][j], numtri[i-1][j-1]);
        }
    }
    int result = 0;
    for(int i=0;i<n;i++){
        result = max(result, numtri[n-1][i]);
    }

    ofstream fout ("numtri.out");
    fout << result << endl;
    fout.close();
    return 0;
}
