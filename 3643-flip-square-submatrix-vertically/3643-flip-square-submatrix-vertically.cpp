class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& g, int x, int y, int k) {
        
        vector<vector<int>> v(k, vector<int>(k));

        // copy submatrix
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                v[i][j] = g[x + i][y + j];
            }
        }

        // reverse rows
        reverse(v.begin(), v.end());

        // put back
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                g[x + i][y + j] = v[i][j];
            }
        }

        return g;
    }
};