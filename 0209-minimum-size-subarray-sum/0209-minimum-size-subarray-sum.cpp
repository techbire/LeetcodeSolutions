class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len=INT_MAX;
        int left=0,currsum=0;
        for(int right=0;right<nums.size();right++){
            currsum+=nums[right];
            while(currsum>=target){
                if(right-left+1<min_len){
                  min_len=right-left+1;
                }
                currsum-=nums[left];
                left++;
            }
        }
        return min_len!=INT_MAX?min_len:0;

    }
};