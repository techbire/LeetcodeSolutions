class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
      
          for(int size =nums.size()-1 ; size>=1;size--){
            for (int i = 0;i<size;i++){
                 nums[i] = (nums[i]+nums[i+1])%10;
            }
           
          }
      return nums[0];
    }
};