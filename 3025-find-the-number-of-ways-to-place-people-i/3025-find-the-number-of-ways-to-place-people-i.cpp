class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(),
             [](auto &a, auto &b) {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] > b[1];
             });
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int yi = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int yj = points[j][1];
                if (yj <= yi && yj > maxY) {
                    ans++;
                    maxY = yj;
                }
            }
        }
        return ans;
    }
};