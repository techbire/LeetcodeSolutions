class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
 int row=matrix.size()-1;
        int column=0;
        while(row>=0 && column <matrix[0].size()){
            if(matrix[row][column]==target){
                return true;
            }
            if(matrix[row][column]<target){
                column++;
            }else{
                row--;
            }
        }
        return false;
    }
};