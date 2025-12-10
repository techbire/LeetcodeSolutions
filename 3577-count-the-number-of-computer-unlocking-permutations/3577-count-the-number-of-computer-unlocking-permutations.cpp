class Solution {
using ll=long long;
public:
    int fact(int _n){
        ll n = _n;
        ll mod  = 1e9 + 7;
        ll ans = 1;
        for(ll i = n;i>=1;i--){
            ans = (ans*i)%mod;
        }
        return ans%mod;
    }
    int countPermutations(vector<int>& a) {
        int n = a.size();
        int val  = a[0];
        for(int i = 1;i<n;i++){
            if(a[i]<val || a[i]==val){
                return 0;
            }
        }
        int ans = fact(n-1);
        return ans;
    }
};