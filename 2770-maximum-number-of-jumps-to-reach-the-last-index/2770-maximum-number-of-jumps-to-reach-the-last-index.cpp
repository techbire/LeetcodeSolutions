class Solution {
public:
    int maximumJumps(vector<int>& a, int t) {
        int n = a.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; j++) {

                if (abs(a[i] - a[j]) <= t) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};