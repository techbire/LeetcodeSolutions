class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, cnt = 0;
        int n = nums.size();
        nums.push_back(-1);
        for (int i = 0; i <= n; i++) {
            if (nums[i] == 0)
                cnt++;
            else {
                res += (cnt * (cnt - 1)) / 2;
                cnt = 0;
            }
        }
        return res;
    }
};