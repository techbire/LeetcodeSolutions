class Solution {
public:
    long long minimumSteps(string s) {
        long long steps=0;
        int count1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')count1++;
            else steps+=count1;
        }
        return steps;  
    }
};