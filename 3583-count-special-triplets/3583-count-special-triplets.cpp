class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;
        for (int x : nums) right[x]++;

        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            right[nums[j]]--; // j is no longer in right side
            long long val = nums[j] * 2LL;
            ans = (ans + left[val] * right[val]) % MOD;
            left[nums[j]]++; // now j moves to left side
        }
        return ans % MOD;
    }
};