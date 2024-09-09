class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
       unordered_map<int , int>mp;
       set<int> s;
       vector<int> :: iterator it;
       for(int i = 0; i<nums1.size(); i++){
        if(mp.find(nums1[i]) == mp.end()){
            mp[nums1[i]] = 1;
        }
        else{
            mp[nums1[i]++];
        }
       }
       
       for ( int j = 0; j < nums2.size(); j++){
        auto it = mp.find(nums2[j]);
        if(it != mp.end()){
  
            if(s.find(it->first) == s.end()){
                s.insert(it->first);
                ans.push_back(it->first);            
            }
       }
       }
       return ans;
    }
};