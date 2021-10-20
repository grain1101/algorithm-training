
const int INF = 1e9;
int n;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
typedef pair<int, int> PII;
class Solution {
 public:
  int secondMinimum(int nn, vector<vector<int>> &edges, int time, int change) {
    n = nn;
    vector<vector<int>> g(n + 1);
    vector<int> dis(n + 1, INF);
    vector<int> dis2(n + 1, INF);
    for (auto &v : edges) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
    }
    dis[1] = 0;
    min_heap<PII> mh;
    mh.push(PII(0, 1));
    while (!mh.empty()) {
      auto p = mh.top();
      mh.pop();
      int u = p.second;
      int x = p.first;
      if (dis2[u] < x) continue;
      for (auto v : g[u]) {
        int t = x;
        if ((t / change) % 2) t += change - t % change;
        t += time;
        bool z = t == dis[v];
        if (t < dis[v]) {
          swap(t, dis[v]);
          mh.push(PII(dis[v], v));
        }
        if (!z && t < dis2[v]) {
          dis2[v] = t;
          mh.push(PII(dis2[v], v));
        }
      }
    }
    return dis2[n];
  }
};
