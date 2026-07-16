class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        //all lower
        for(char ch:s){
           if(isalnum(ch)){
            res+=tolower(ch);
           } 
        }
        string rev = res;
        reverse(rev.begin(), rev.end());
        return res==rev;
    }
};