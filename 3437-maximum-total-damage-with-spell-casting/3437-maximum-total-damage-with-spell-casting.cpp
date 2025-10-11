#define ll long long
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<pair<int, ll>> dp(6, {0, 0});
        int ix = 5;
        int n = 0;
        for (int i = 0; i < power.size(); i++) {
            int ix1 = ix % 6;
            dp[ix1] = {power[i], (ll)power[i]};
            while (i + 1 < power.size() && power[i + 1] == power[i])
                dp[ix1].second += (ll)power[i++];
            ll maxi = 0;
            for (int i = ix - 1, l = 0; i > ix - 6; i--) {
                int j = i % 6;
                if (dp[ix1].first - dp[j].first > 2) {
                    maxi = max(maxi, dp[j].second);
                    if (++l == 3)
                        break;
                }
            }
            dp[ix1].second += maxi;
            ix++;
        }
        ll ans = 0;
        for (int i = 0; i < 6; i++)
            ans = max(ans, dp[i].second);
        return ans;
    }
};