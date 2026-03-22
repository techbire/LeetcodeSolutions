class Solution {
public:
    bool findRotation(vector<vector<int>>& a, vector<vector<int>>& b) {
        for(int k=0;k<4;k++){
            if(a==b) return 1;
            for(int i=0;i<a.size();i++)
                for(int j=0;j<i;j++)
                    swap(a[i][j],a[j][i]);
            for(int i=0;i<a.size();i++)
                reverse(a[i].begin(),a[i].end());
        }
        return 0;
    }
};