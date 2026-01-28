class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k > n) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(l <= r) {
            int day = l + (r - l) / 2;

            int bouquets = 0;
            int cnt = 0;

            for(int i = 0; i < n; i++) {
                if(bloomDay[i] > day) {
                    cnt = 0;
                } else {
                    cnt++;
                    if(cnt == k) {
                        bouquets++;
                        cnt = 0;
                    }
                }
            }

            if(bouquets >= m) {
                ans = day;
                r = day - 1;
            } else {
                l = day + 1;
            }
        }
        return ans;
    }
};
