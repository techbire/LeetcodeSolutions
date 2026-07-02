class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    // int ans=0;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     int count=0;
    //     for(int j=i;j<n;j++){
    //     if(nums[j]==0)count++;
    //     if(count>k)break;
    //     ans=max(ans,j-i+1);}
    // }   
    // return ans;
    // }


        int l = 0;
        int zero = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] == 0)
                zero++;
            while(zero > k) {
                if(nums[l] == 0)
                    zero--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};