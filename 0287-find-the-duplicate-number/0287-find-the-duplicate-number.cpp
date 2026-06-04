class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctindex=nums[i];
            if(nums[correctindex]==nums[i])return nums[i];
            else swap(nums[i],nums[correctindex]);
        }
   return -1; }
};