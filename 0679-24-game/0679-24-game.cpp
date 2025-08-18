class Solution {
public:
    const double EPS = 1e-6; // small tolerance for floating point comparison
    
    // Recursive function to check if we can make 24
    bool solve(vector<double> nums) {
        // Base case: only one number left
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }
        
        // Try all pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                
                // Remaining numbers after removing nums[i] and nums[j]
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                double a = nums[i], b = nums[j];
                
                // Try all operations
                vector<double> results = {a + b, a - b, a * b};
                if (fabs(b) > EPS) results.push_back(a / b); // avoid divide by zero
                
                // Recurse on each result
                for (double res : results) {
                    next.push_back(res);
                    if (solve(next)) return true;
                    next.pop_back(); // backtrack
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        // Convert int -> double for safe division
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
