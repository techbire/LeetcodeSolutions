class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0ll); //sum happen
        if (sum % p == 0) return 0;

        vector<long long> res(n);
        for (int i = 0; i < n; i++) res[i] = 1ll * nums[i]; //res = {x,x,x,x}

        for (int j = 1; j < n; j++) {
            bool check = false;
            for (int i = 0; i < n && !check; i++) {  //traversing both array where j is finding possibility of finding sumation of p;
                if ((sum - res[i]) % p == 0) return j;
                if (i + j < n) res[i] += nums[i + j];
                else check = true;
            }
        }
        return -1;
    }
};