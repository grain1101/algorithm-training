#include "leetcode.h"
/*
Union-Find
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
      Make small set union to big set.
Union: Join two subsets into a single subset.

Optimization:
    1. Path compression.
    2. Union by size.

Usage:
    1. How many sets are there after applying union rules.
    2. Check whether an undirected graph contains cycle or not.
*/

class UnionFind{
private:
    vector<int> p;
    int cnt;
public:
    UnionFind(int n){
        p.assign(n, -1);
        cnt = n;
    }
    bool Union(int x, int y){
        int rx = Find(x), ry = Find(y);
        if (rx == ry) return false;
        cnt--;
        if (p[rx] < p[ry]) p[rx] += p[ry], p[ry] = rx;
        else p[ry] += p[rx], p[rx] = ry;
        return true;
    }
    int Find(int x){
        return p[x] < 0 ? x : (p[x] = Find(p[x]));
    }
    int getCnt(){
        // negative number is root;
        return cnt;
    }
};

typedef pair<int, int> PII;
class Solution {
public:
    bool isTree(vector<PII>& edges){
        int n = edges.size();
        UnionFind uf(n + 1);
        for(const auto& e : edges){
            if (!uf.Union(e.first, e.second)) return false;
        }
        return uf.getCnt() == 1;
    }
};

int main() {
    Solution s1;
    vector<PII> edges= {{0,1},{1,2}, {3,4}, {2,3}, {3,1}};

    cout << s1.isTree(edges) << endl;
}
