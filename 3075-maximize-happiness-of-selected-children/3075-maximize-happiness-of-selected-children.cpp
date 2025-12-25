class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0;
        int temp = 0;
        sort(h.begin(), h.end());
        for (int i = h.size() - 1; i >= 0; i--) {
            long long currentH = h[i] - temp;
            if (currentH < 0)
                currentH = 0;
            ans += currentH;
            temp++;
            k--;
            if (k == 0)
                break;
        }
        return ans;
    }
};