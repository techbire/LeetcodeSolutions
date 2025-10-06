class Solution {
public:
    int swimInWater(vector<vector<int>> &g) {
        int n = g.size(), lo = g[0][0], hi = n * n - 1;
        auto can = [&](int t) {
            vector<vector<int>> vis(n, vector<int>(n));
            queue<pair<int,int>> q;
            if (g[0][0] > t) return false;
            q.push({0,0}), vis[0][0] = 1;
            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            while(!q.empty()){
                auto [x,y]=q.front(); q.pop();
                if(x==n-1 && y==n-1) return true;
                for(auto &d:dirs){
                    int i=x+d[0], j=y+d[1];
                    if(i>=0&&j>=0&&i<n&&j<n&&!vis[i][j]&&g[i][j]<=t)
                        vis[i][j]=1, q.push({i,j});
                }
            }
            return false;
        };
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(can(mid)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};