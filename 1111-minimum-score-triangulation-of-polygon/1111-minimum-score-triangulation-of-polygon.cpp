class Solution {
public:
    int dp[51][51];
    int find(int i, int j, vector<int>& v) {
        if (i >= j - 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int curr = find(i, k, v) + find(k, j, v) + (v[i] * v[j] * v[k]);
            res = min(res, curr);
        }
        return dp[i][j] = res;
    }
    int minScoreTriangulation(vector<int>& v) {
        memset(dp, -1, sizeof(dp));
        return find(0, v.size() - 1, v);
    }
};