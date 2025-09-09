class Solution {
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<int> arr(n, 0);
        arr[0] = 1;

        for(int i=0; i<n; i++){
            for(int j = i+delay; j<i+forget && j<n; j++){
                arr[j] = (arr[j] + arr[i] )%mod;
            }
        }

        int ans = 0;
        for(int i=n-forget; i<n; i++){
            ans= (ans + arr[i])%mod;
        }

        return ans;

    }
};