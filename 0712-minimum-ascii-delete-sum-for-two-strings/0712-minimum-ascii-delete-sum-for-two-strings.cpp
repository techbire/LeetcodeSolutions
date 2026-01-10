class Solution {
public:
    int lcs(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,-1));
        for(int i=0;i<=s1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=s2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i - 1][j - 1] + text1[i - 1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int total=0,pt=lcs(s1,s2);
        for(auto it:s1){
            total+=it;
        }
        for(auto it:s2){
            total+=it;
        }
        return total-2*pt;
    }
};