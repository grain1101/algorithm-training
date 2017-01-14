/*
ID: crazyco3
PROG: ariprog
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

int n, m;

int isbisquare[125010];
int bisquare[40000], nb;
int maxs = 10000;

int main() {
    ifstream fin ("ariprog.in");
    fin >> n >> m;
    fin.close();
    for(int i = 0; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            int k = i * i + j * j;
            isbisquare[k] = 1;
        }
    }
    for(int i = 0; i < 125010; i++) {
        if (isbisquare[i]) bisquare[nb++] = i;
    }
    vector<PII> result;
    for(int i = 0; i < nb; i++) {
        int a = bisquare[i];
        if (result.size() > maxs) continue;
        for(int j = i + 1; j < nb; j++) {
            if (result.size() > maxs) continue;
            int d = bisquare[j] - a;
            if (a + (n - 1) * d > bisquare[nb - 1]) break;
            bool flag = true;
            int tmp = a;
            for(int k = 1; k < n; k++, tmp += d) if (!isbisquare[tmp + d]) flag = false;
            if (flag) result.push_back({d, a});
        }
    }
    sort(result.begin(), result.end());

    ofstream fout ("ariprog.out");
    if (result.size() == 0) fout << "NONE" << endl;
    for(auto& p : result) {
        fout << p.second << " " << p.first << endl;
    }
    fout.close();
    return 0;
}
