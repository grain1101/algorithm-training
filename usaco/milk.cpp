/*
ID: crazyco3
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;
typedef pair<int, int> PII;

void show(const vector<PII>& a)
{
    for (auto &t : a)
    {
        cout << t.first << " " << t.second << endl;
    }
}

bool cmp(const PII a, const PII b)
{
    return a.first < b.first;
}



int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n,m;
    fin >> n >> m;

    vector<PII> farmers;
    for(int i=0;i<m;i++)
    {
        int a,b;
        fin >> a >> b;
        farmers.push_back({a,b});
    }

    sort(farmers.begin(), farmers.end(), cmp);
    int tmp = 0;
    int cost = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<farmers[i].second;j++)
        {
            if(tmp == n)
            {
                fout << cost << endl;
                return 0;
            }
            tmp++;
            cost += farmers[i].first;

        }
    }
    fout << cost << endl;
    return 0;
}
