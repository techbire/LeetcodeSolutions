class Solution {
public:
    vector<vector<int>>dp;
    int solve(string&s,string&t,int n,int m){
        if(n==0||m==0){
            return 0;
        }
        if (dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n-1]==t[m-1]){
            return dp[n][m]=1+solve(s,t,n-1,m-1);
        }
        else{
            return dp[n][m]=max(solve(s,t,n-1,m),solve(s,t,n,m-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        int m=t.length();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(s,t,n,m);
    }
};