class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n=a.size(),p=1,s=1;
        vector<int> r(n,1);
        for(int i=0;i<n;i++) r[i]=p,p*=a[i];
        for(int i=n-1;i>=0;i--) r[i]*=s,s*=a[i];
        return r;
    }
};