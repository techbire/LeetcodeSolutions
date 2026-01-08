class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, -1e9));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int p = a[i] * b[j];
                dp[i][j] = p;
                if(i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + p);
                if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
