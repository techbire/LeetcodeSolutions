class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxM = 0;

        for (int c = n - 2; c >= 0; --c) {
            for (int r = 0; r < m; ++r) {
                if (r > 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    dp[r][c] = max(dp[r][c], dp[r - 1][c + 1] + 1);
                }
                if (grid[r][c] < grid[r][c + 1]) {
                    dp[r][c] = max(dp[r][c], dp[r][c + 1] + 1);
                }
                if (r < m - 1 && grid[r][c] < grid[r + 1][c + 1]) {
                    dp[r][c] = max(dp[r][c], dp[r + 1][c + 1] + 1);
                }
            }
        }

        for (int r = 0; r < m; ++r) {
            maxM = max(maxM, dp[r][0]);
        }

        return maxM;
    }
};
