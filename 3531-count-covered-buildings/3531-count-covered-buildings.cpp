class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<int> rowmax(n+1,INT_MIN),
        rowmin(n+1,INT_MAX),
        colmax(n+1,INT_MIN),
        colmini(n+1,INT_MAX);
        for(auto &i:b){
            int x=i[0],y=i[1];
            rowmax[x]=max(y,rowmax[x]);
            rowmin[x]=min(rowmin[x],y);
            colmax[y]=max(colmax[y],x);
            colmini[y]=min(colmini[y],x);
        }
        int ans=0;
        for(auto &i:b){
            int x=i[0],y=i[1];
            if(rowmax[x]>y && rowmin[x]<y && colmax[y]>x && colmini[y]<x) ans++;
       }return ans;
    }
};