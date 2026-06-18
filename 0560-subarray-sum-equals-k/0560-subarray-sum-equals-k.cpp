class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int prefixSum = 0;
        int totalSubarrays = 0;

        for (int num : nums) {
            prefixSum += num;

            if (prefixCount.count(prefixSum - k)) 
                totalSubarrays += prefixCount[prefixSum - k];

            prefixCount[prefixSum]++;
        }

        return totalSubarrays;
    }
};