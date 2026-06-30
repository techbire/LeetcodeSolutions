class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
        if(prefix[j+1]-prefix[i]==k){
        ans++;
        }
        }
        }
return ans;}
};

//     unordered_map<int,int>mp;
//     int sum=0;
//     int ans=0;
//     mp[sum]=1;
//     for(auto it:nums){
//         sum+=it;
//         int find=sum-k;
//         if(mp.find(find)!=mp.end()){
//             ans+=mp[find];
//         }
//         mp[sum]++;
//     }
//     return ans;
    
//         }
// };