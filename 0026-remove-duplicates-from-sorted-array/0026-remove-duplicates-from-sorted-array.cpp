class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n=nums.size();
    int uni=0;
    for(int i=1;i<n;i++){
        if(nums[uni]!=nums[i]){
      
        nums[uni+1]=nums[i];
        uni++;
    }   
    }
    return uni+1;
    }
};