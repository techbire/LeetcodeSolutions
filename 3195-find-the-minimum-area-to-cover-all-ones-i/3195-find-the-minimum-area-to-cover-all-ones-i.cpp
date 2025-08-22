class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
 int m = grid.size();
        int n = grid[0].size();

        int minRow = INT_MAX;
        int maxRow = INT_MIN;
        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]){

                    minRow = min(minRow,i);
                    maxxRow = max(maxRow,i);
                    minCol = min(minCol,j);
                    maxCol = max(maxCol,j);
                }
            }
        }
        if(maxRow==INT_MIN){

            return 0;
        }
        return (maxRow - minRow + 1)*(maxCol - minCol + 1);
    }
};