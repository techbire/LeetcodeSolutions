class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n);
        dp[0] = true;

        int reach = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump && dp[i - minJump]) reach++;
            if (i > maxJump && dp[i - maxJump - 1]) reach--;

            dp[i] = (s[i] == '0' && reach > 0);
        }

        return dp[n - 1];
    }
};