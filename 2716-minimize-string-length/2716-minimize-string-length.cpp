class Solution {
public:
    int minimizedStringLength(string s) {
        string ans ="";
        sort(s.begin(),s.end());
        for(int i = 1 ; i<s.length();i++ ){
            if(s[i]!=s[i-1]){
                ans+=s[i];
            }
        }
        return ans.length()+1;
    }
};