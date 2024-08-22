class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     if(strs.size()==1) return strs[0];
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string first= strs[0];
        string last=strs[n-1];
        string s= "";
        //loop till small character 
        for(int i=0;i<(min(first.size(),last.size()));i++){
            if(first[i]==last[i]){
                s+=last[i];
            }
        else return s;}
    return s;}
};