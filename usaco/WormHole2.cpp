/*
ID: crazyco3
PROG: wormhole
LANG: C++11
*/
#include<iostream>
#include<fstream>
using namespace std;

#define MAX_N 12

int n, X[MAX_N+1], Y[MAX_N+1];
int paired[MAX_N+1];
int next_on_right[MAX_N+1];

bool hasCircle()
{
    for(int start=1;start<=n;start++){
        int pos = start;
        for(int cnt=0;cnt<n;cnt++){
            pos = next_on_right[paired[pos]];
        }
        if(pos!=0) return true;
    }
    return false;
}

int Solve()
{
    // find first unpaired wormhole
    int i, total = 0;
    for(i=1;i<=n;i++){
        if(paired[i]==0) break;
    }
    // every point paired
    if(i>n){
        if(hasCircle()) return 1;
        else return 0;
    }

    for(int j=i+1;j<=n;j++){
        if(paired[j]==0){
            paired[i]=j;
            paired[j]=i;
            total += Solve();
            paired[i]=0;
            paired[j]=0;
        }
    }
    return total;
}

int main()
{
    ifstream fin ("wormhole.in");
    fin >> n;
    for(int i=1;i<=n;i++){
        fin >> X[i] >> Y[i];
    }
    fin.close();

    // generate nextP
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Y[i]==Y[j] && X[i] < X[j]){
                if(next_on_right[i]==0 || X[j] < X[next_on_right[i]])
                    next_on_right[i] = j;
            }
        }
    }
    ofstream fout ("wormhole.out");
    fout << Solve() << endl;
    fout.close();
    return 0;
}
