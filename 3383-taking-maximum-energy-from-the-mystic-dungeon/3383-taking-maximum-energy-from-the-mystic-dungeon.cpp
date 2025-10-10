class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
    int maxi=-1e9;
    int n=energy.size();
    vector<int>vis(n,0);
    int sum=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            continue;
        }
        int j=i;
        sum=0;
        while(j<n){
            vis[j]=1;
            sum+=energy[j];
            sum=max(sum,energy[j]);

        j+=k;
        }
        maxi=max(maxi,sum);
    }
    return maxi;

    }    
};