class Solution {
public:
    vector<int> lisLen(vector<int>& v) {
        vector<int> lis = {v[0]}, lisLen(v.size(), 1);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > lis.back()) {
                lis.push_back(v[i]);
            } else {
                int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
                lis[idx] = v[i];
            }
            lisLen[i] = lis.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis = lisLen(nums);
        reverse(nums.begin(), nums.end());
        vector<int> lds = lisLen(nums);
        reverse(lds.begin(), lds.end());

        int minRemovals = INT_MAX;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                minRemovals = min(minRemovals, n - (lis[i] + lds[i] - 1));
            }
        }
        return minRemovals;
    }
};