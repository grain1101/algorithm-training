/*
ID: crazyco3
PROG: wormhole
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

ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

int result = 0;
int n;
vector<PII> point;

void show(const vector<vector<int>>& t){
    for(auto& tt : t){
        for(auto& ttt: tt)
            cout << ttt << "  ";
    cout << endl;
    }

}

bool isLeft(int p1, int p2){
    if(point[p1].second == point[p2].second && point[p1].first < point[p2].first){
        for(auto& p:point){
            if(p.second == point[p1].second && point[p1].first < p.first && p.first < point[p2].first) return false;
        }
        return true;
    }
    return false;
}

void hasCircle(const vector<vector<int>>& edges, int node, bool& flag, vector<int>& color){
    if(flag){
        return;
    }
    // color: 0->white; 1->grey; 2->black;
    color[node] = 1;
    for(int i=0;i<edges.size();i++){
        if(edges[node][i] == 1){
            if(color[i] == 2) continue;
            if(color[i] ==1) {
                flag = true;
                return;
            }
            hasCircle(edges,i,flag,color);
        }
    }

}

bool Stucked(const vector<PII>& pairs){
    //1. y1==y2
    int num = pairs.size();
    if(num==0) return false;
    for(auto p : pairs){
        if(isLeft(p.first, p.second) || isLeft(p.second, p.first)) return true;
    }
    //2. portal -> portal2 p1->p3 || p1->p4 || p2->p3 || p2->p4
    vector<vector<int>> edges(num, vector<int>(num,0));
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            int p1 = pairs[i].first;
            int p2 = pairs[i].second;
            int p3 = pairs[j].first;
            int p4 = pairs[j].second;
            if(isLeft(p1, p3) || isLeft(p1, p4) || isLeft(p2, p3) || isLeft(p2,p4))
                edges[i][j] = 1;
        }
    }

    //3. Is cycle graph
    vector<int> color(edges.size(),0);
    bool flag = false;
    hasCircle(edges,0,flag,color);
    return flag;
}

void dfs(vector<PII>& pairs, vector<int>& mark){
    if(pairs.size() == n/2){
        if(Stucked(pairs)){
            result++;
            for(auto& p:pairs){
                cout << "("<<p.first<<","<<p.second<<")";
            }
            cout << endl;
        }
        return;
    }
    // ensure all pairs are in order
    int p = 0;
    if(pairs.size()>0){
        p = pairs[pairs.size()-1].first+1;
    }

    for(int i=p;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mark[i]!=1 && mark[j]!=1){
                pairs.push_back({i,j});
                mark[i] = 1;
                mark[j] = 1;
                dfs(pairs, mark);
                pairs.pop_back();
                mark[i] = 0;
                mark[j] = 0;
            }

        }
    }
}


int main() {

    // 0. input lock
    int tmp;
    fin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        fin >> x >> y;
        point.push_back({x,y});
    }

    // 1. all points Pairs
    vector<PII> pairs;
    vector<int> mark(n,0);

    dfs(pairs, mark);
    cout << result << endl;

    return 0;
}
