class Solution {
public:
    int search(vector<int>& nums, int target) {
    int left=0;
    int n=nums.size();
    int ans=-1;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){ans=mid;right=mid-1;}
        else if(nums[mid]<target){left=mid+1;}
        else {right=mid-1;}
    }
    return ans;
    }
};

