class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {

            // Avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int lo = i + 1, hi = n - 1;

            // Use two pointers to find pairs that sum to (0 - nums[i])
            while (lo < hi) {
                int current = nums[i] + nums[lo] + nums[hi];

                if (current == 0) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});

                    // Avoid duplicates for lo and hi
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;

                    lo++;
                    hi--;
                }
                else if (current < 0) {
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }

        return ans;
    }
};