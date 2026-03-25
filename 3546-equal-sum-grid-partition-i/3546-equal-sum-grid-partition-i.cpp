class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        long long tot = 0;
        for(auto &r : g)
            for(auto x : r)
                tot += x;

        if(tot % 2) return false;

        long long need = tot / 2;

        // row-wise check
        long long s = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                s += g[i][j];
            }
            if(s == need) return true;
        }

        // column-wise check
        s = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                s += g[i][j];
            }
            if(s == need) return true;
        }

        return false;
    }
};