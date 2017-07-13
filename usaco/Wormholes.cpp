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

bool isLeft(int p1, int p2){
    if(point[p1].second == point[p2].second && point[p1].first < point[p2].first){
        for(auto& p:point){
            //p.first -> x; p.second ->y
            // A -> B -> C; so A is not Left of C
            if(p.second == point[p1].second && point[p1].first < p.first && p.first < point[p2].first) return false;
        }
        return true;
    }
    return false;
}

int in[16];
int out[16];
vector<int> portal;
vector<int> rightp;
void hasCircle(int node, bool& flag){
    if(flag){
        return;
    }
    // color: 0->white; 1->grey; 2->black;
    // every point has two part: in and out. If go through portal, out make as grey.
    in[node] = 1;
    int next = portal[node];
    if (out[next] == 2) return;
    if (out[next] == 1) {
      flag = true;
      return;
    }
    out[next] = 1;
    if (rightp[next] != -1) {
      int nextnode = rightp[next];
      if (in[nextnode] == 0) hasCircle(nextnode, flag);
      else if (in[nextnode] == 1) {
        flag = true;
        return;
      }
    }
    out[next] = 2;
    in[node] = 2;
}

bool Stucked(const vector<PII>& pairs){
  portal.assign(n, 0);
  for(auto& p : pairs) {
    portal[p.first] = p.second;
    portal[p.second] = p.first;
  }
  for(int i = 0; i < n; i++){
    fill(in, in+n, 0);
    fill(out, out+n,0);
    bool flag = false;
    hasCircle(i,flag);
    if(flag) return true;
  }
  return false;
}

void dfs(vector<PII>& pairs, vector<int>& mark){
    if(pairs.size() == n/2){
        if(Stucked(pairs)){
            result++;
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
    rightp.assign(n, -1);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if (isLeft(i, j)) {
          rightp[i] = j;
        }
      }
    }
    // 1. all points Pairs
    vector<PII> pairs;
    vector<int> mark(n,0);

    dfs(pairs, mark);
    fout << result << endl;

    return 0;
}
