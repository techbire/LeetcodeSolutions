using ll = long long;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        ll currsum = 0;
        ll maxisum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            currsum += nums[right];
            freq[nums[right]]++;

            while (freq[nums[right]] > 1 || right - left + 1 > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                currsum -= nums[left];
                left++;
            }

            if (right - left + 1 == k)
                maxisum = max(maxisum, currsum);
        }

        return maxisum;
    }
};