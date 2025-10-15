class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int knew = k-1;
        if(knew == 0)return true;
        for(int j=k+1;j<nums.size();j++){
            if(nums[j] > nums[j-1] && nums[j-k] > nums[j-k-1])knew--;
            else knew = k - 1;
            if(knew == 0)return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int n=nums.size(),low=1,high=n,res=INT_MIN;
        while(low<=high){

            int mid=(low+high)/2;
            
            if(hasIncreasingSubarrays(nums,mid)){
                res=mid;
                low=mid+1;}
            else{
                high=mid-1;
            }
            }

        return res;



    }
};