class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();

        auto check = [&](int mid) {
            int cnt = 1;
            int last = price[0];

            for (int i = 1; i < n; i++) {
                if (price[i] - last >= mid) {
                    cnt++;
                    last = price[i];
                }
            }
            return cnt >= k;
        };

        int low = 0;
        int high = price[n-1] - price[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;   
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
