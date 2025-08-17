class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        if (K == 0 || N >= K + maxPts) return 1.0;
        vector<double> dp(N+1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0, ans = 0.0;

        for (int i = 1; i <= N; i++) {
            dp[i] = windowSum / maxPts;
            if (i < K) windowSum += dp[i];
            else ans += dp[i];
            if (i - maxPts >= 0) windowSum -= dp[i - maxPts];
        }
        return ans;
    }
};