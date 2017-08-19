/**
struct wp {
    std::vector<wp*> fronts
    std::vector<wp*> backs
    wp* left
    wp* right
}

    nextFront 
left  curWp  right
      back
*/      
class SearchFurthestChagePath{
public:
    void SearchFurthestChangePath(const wp& start_wp, const wp& end_wp, const double& max_search_distance, std::vector<wp*> out_path) {
        if (start_wp == end_wp) return;
        sw = start_wp;
        ew = end_wp;
        maxDistance = max_search_distance;
        this.out_path = out_path;
        vector<wp*> tmpPath;
        int furthestWp = 0;
        dfs(start_up, tmpPath, 0, furthestWp, false);
    }
private:
    wp sw;
    wp ew;
    double maxDistance;
    vector<wp*> out_path;
    unordered_map<wp*, int> m; // [wp, step]
    void dfs(wp& curWp, vector<wp*>& tmpPath, int step, int& furthestWp, bool changed) {
        if (curWp == end_wp) {
            if (step > furthestWp) {
                furthestWp = step;
                out_path = tmpPath;
            }
            return;
        }
        if (step > maxDistance || changed && step < furthesWp || m.find(curWp) != m.end()) return;
        m[curWp] = step;
        // wp.fronts
        for(auto nextFront : curWp.fronts) {
            if (m.find(nextFront) != m.end()) continue;       
            tmpPath.push_back(curWp);
            dfs(nextFront, tmpPath, step + 1, furthestWp, changed);
            tmpPath.pop_back();
        }
        // wp.left
        tmpPath.push_back(curWp.left);
        dfs(curWp.left, tmpPath, step + (changed) ? 0 : 1, furthesWp, true);
        tmpPath.pop_back();
        // wp.right
        tmpPath.push_back(curWp.right);
        dfs(curWp.right, tmpPath, step + (changed) ? 0 : 1, furthesWp, true);
        tmpPath.pop_back();
    }    
};
