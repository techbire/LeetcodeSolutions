class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int n = nums.size() / 2;
        // Count 
        for (int num : nums) {
            freqMap[num]++;
        }
        // Find majority 
        for (int num : nums) {
            if (freqMap[num] > n) {
                return num;
            }
        }
        return -1;
    }
};