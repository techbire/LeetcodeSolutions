class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.empty()) return -1;
        
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[low]<=nums[high]){   //becoz if array has single element
                ans=min(ans,nums[low]);
                break;
            }else if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);    // left half sorted
                low=mid+1;
            }else{
                ans=min(ans,nums[mid]);
                high=mid-1;  //right half sorted hai
            }
        }

        return ans;
    }
};