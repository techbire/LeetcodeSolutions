class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        bool flag=false;
        int count=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]) count++;
            else{
                if(count<k){
                    count=1;
                    flag=false;
                }
                else if(count>=k){
                    flag=true;
                    count=1;
                }
            }
            if(count>=2*k || (flag && count>=k)) return true;
        }
        return false;
    }
};