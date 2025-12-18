class Solution {
public:
    using ll = long long;

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> act(n), sum(n);

        act[0] = (ll)prices[0] * strategy[0];
        sum[0] = prices[0];

        for (int i = 1; i < n; i++) {
            act[i] = act[i - 1] + (ll)prices[i] * strategy[i];
            sum[i] = sum[i - 1] + prices[i];
        }
        ll ans = act[n - 1];

        // sliding window of size k
        for (int i = 0; i + k - 1 < n; i++) {
            int j = i + k;       // end + 1
            int h = k / 2;       // half window

            // left unchanged
            ll left = (i > 0) ? act[i - 1] : 0;

            // right unchanged
            ll right = (j < n) ? (act[n - 1] - act[j - 1]) : 0;

            // middle changed part
            ll mid = sum[j - 1] - ((i + h - 1 >= 0) ? sum[i + h - 1] : 0);

            ans = max(ans, left + mid + right);
        }

        return ans;
    }
};