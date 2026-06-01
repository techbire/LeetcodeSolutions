class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = n - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) {
            pivot--;
        }
        if (pivot >= 0) {
            int nextGreater = n - 1;
            while (nums[nextGreater] <= nums[pivot]) {
                nextGreater--;
            }
            swap(nums[pivot], nums[nextGreater]);
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};