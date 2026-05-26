class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        int num_pairs = n / 2;
        for(int i = 0; i < num_pairs; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int mn = min(a, b);
            int mx = max(a, b);
            int sum = a + b;
            // Initially every pair needs 2 moves
            diff[2] += 2;
            // Range where 1 move is enough
            diff[mn + 1] -= 1;
            diff[mx + limit + 1] += 1;
            // Exact sum needs 0 move
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }
        int ans = INT_MAX;
        int current = 0;
        for(int sum = 2; sum <= 2 * limit; sum++) {
            current += diff[sum];
            ans = min(ans, current);
        }
        return ans;
    }
};