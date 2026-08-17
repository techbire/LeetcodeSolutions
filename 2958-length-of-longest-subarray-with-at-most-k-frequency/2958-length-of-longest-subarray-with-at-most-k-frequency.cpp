class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //approach
        // k ke accordingly har ek element ka fq decide hoga then we return length of final subarray !
       int r,l=0,n=nums.size(),ans=0;
       unordered_map<int,int>fq;
       for(r=0;r<n;r++){
        fq[nums[r]]++;
        while(fq[nums[r]]>k){
            fq[nums[l]]--;
            l++;
        
        }
       int len=r-l+1;
       ans=max(ans,len);
       }
       return ans;

    }
};