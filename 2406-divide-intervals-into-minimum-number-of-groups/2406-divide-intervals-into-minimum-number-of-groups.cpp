class Solution {
public:
        int minGroups(vector<vector<int>>& iv) {
        vector<pair<int, int>> vp;
        for (auto& it : iv) {
            vp.push_back({it[0], 1});
            vp.push_back({it[1] + 1, -1});
        }
        sort(vp.begin(), vp.end());
        
        int maxG = 1, cnt = 0;
        for (auto& p : vp) {
            cnt += p.second;
            maxG = max(maxG, cnt);
        }
        
        return maxG;
    }
};