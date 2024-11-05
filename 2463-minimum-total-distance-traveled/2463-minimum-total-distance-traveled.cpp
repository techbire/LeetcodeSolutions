class Solution {
public:
    const long long inf = 1e15;
    
    long long solve(int i, int j, vector<int>& r, vector<vector<int>>& f, vector<vector<long long>>& dp) {
        if (i == r.size()) return 0;
        if (j == f.size()) return inf;

        if (dp[i][j] != inf) return dp[i][j];

        long long ans = inf, dist = 0;
        int k = i;

        for (int t = 1; t <= f[j][1]; ++t) {
            dist += abs(r[k] - f[j][0]);
            ans = min(ans, dist + solve(k + 1, j + 1, r, f, dp));
            if (++k == r.size()) break;
        }
        
        // Option to skip current factory
        ans = min(ans, solve(i, j + 1, r, f, dp));
        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        vector<vector<long long>> dp(r.size(), vector<long long>(f.size(), inf));
        sort(f.begin(), f.end());
        sort(r.begin(), r.end());
        return solve(0, 0, r, f, dp);
    }
};