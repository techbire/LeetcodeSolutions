class Solution {
public:
    int dp[501][501];

    int solve(string &a, string &b, int i, int j) {
        if (i == a.size()) return b.size() - j;
        if (j == b.size()) return a.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (a[i] == b[j]) {
            return dp[i][j] = solve(a, b, i + 1, j + 1);
        }

        int res = 1 + solve(a, b, i, j + 1);      // insert
        res = min(res, 1 + solve(a, b, i + 1, j)); // delete
        res = min(res, 1 + solve(a, b, i + 1, j + 1)); // replace

        return dp[i][j] = res;
    }

    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};
