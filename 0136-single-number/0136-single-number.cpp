class Solution {
public:
    int singleNumber(vector<int>& nums) {
                int result = 0;  // Initialize result as 0
        
        // XOR all numbers in the array
        for (int num : nums) {
            result ^= num;  // XOR current number with result
        }
        
        return result;  // The remaining number is the single one
    }
};
