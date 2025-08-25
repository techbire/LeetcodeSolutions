class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
        int m = mat[0].size();
        int i = 0, j = 0;
        bool b = true;
        vector<int> ans;
        while (ans.size() < n * m) {
            while (i >= 0 && i < n && j >= 0 && j < m) {
                ans.push_back(mat[i][j]);
                i = i + (b ? -1 : 1);
                j = j + (b ? 1 : -1);
            }
            if (j >= m || i>=n) {
                if (b) {
                    i += 2;
                    j -= 1;
                } else {
                    j += 2;
                    i -= 1;
                }
            } else {
                if (b) {
                    i += 1;
                } else {
                    j += 1;
                }
            }
            b = !b;
        }
        return ans;
    }
};