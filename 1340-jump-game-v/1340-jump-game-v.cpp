class Solution {
public:
    int dfs(vector<int>& arr, vector<int>& dp, int i, int d) {
        if(dp[i] != -1)
            return dp[i];
        int ans = 1;
        int n = arr.size();

        for(int j = i + 1; j <= min(n - 1, i + d); j++) {
            if(arr[j] >= arr[i])
                break;
            ans = max(ans, 1 + dfs(arr, dp, j, d));
        }

        for(int j = i - 1; j >= max(0, i - d); j--) {
            if(arr[j] >= arr[i])
                break;
            ans = max(ans, 1 + dfs(arr, dp, j, d));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, dfs(arr, dp, i, d));
        }
        return maxi;
    }
};