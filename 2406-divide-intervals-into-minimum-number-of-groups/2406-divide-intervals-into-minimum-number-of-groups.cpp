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


// //approach
// Sort karo intervals ko unke start time ke hisaab se.
// Event points banao:
// Har interval ka start point [lefti, 1]
// Har interval ka end point [righti + 1, -1]
// Sort karo event points ko.
// Variables set karo: maxG = 1, cnt = 0.
// Process karo event points:
// Increment cnt agar point 1 hai.
// Decrement cnt agar point -1 hai.
// Update maxG = max(maxG, cnt).
// Return karo maxG as minimum groups.