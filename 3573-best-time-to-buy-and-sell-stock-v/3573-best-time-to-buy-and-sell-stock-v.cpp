class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        long long NEG = -1e18;

        // dp[t][state]
        // state: 0 -> free, 1 -> holding(long), 2 -> holding(short)
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;

        for (int price : prices) {
            for (int t = k - 1; t >= 0; t--) {

                // close positions
                if (dp[t][1] != NEG)
                    dp[t + 1][0] = max(dp[t + 1][0], dp[t][1] + price);

                if (dp[t][2] != NEG)
                    dp[t + 1][0] = max(dp[t + 1][0], dp[t][2] - price);

                // open positions
                if (dp[t][0] != NEG) {
                    dp[t][1] = max(dp[t][1], dp[t][0] - price);
                    dp[t][2] = max(dp[t][2], dp[t][0] + price);
                }
            }
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++) {
            ans = max(ans, dp[t][0]);
        }
        return ans;
    }
};
