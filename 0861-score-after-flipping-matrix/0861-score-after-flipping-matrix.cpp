class Solution { public:    int matrixScore(vector<vector<int>>& grid) {        
    int rows = grid.size();       
    int cols = grid[0].size(); 
    
 // Ensure first column is all 1's by flipping rows as needed
        for(int i = 0; i < rows; i++){            
            if(grid[i][0] == 0){                // Flip row
                    for(int j = 0; j < cols; j++){
                        grid[i][j] = (grid[i][j] == 0) ? 1 : 0;
                    }
                }
            }
 // Flip columns where 0's > 1's
        for(int j = 0; j < cols; j++){            int noz = 0, noo = 0;
            for(int i = 0; i < rows; i++){
                if(grid[i][j] == 0){noz++;}
                else noo++;
            }
            if(noz > noo){
                for(int i = 0; i < rows; i++){
                    grid[i][j] = (grid[i][j] == 0) ? 1 : 0;
                }
            }
        }
 // Calculate total score
        int sum = 0;
        for(int i = 0; i < rows; i++){            int x = 1;
            for(int j = cols - 1; j >= 0; j--){
                sum += grid[i][j] * x;
                x *= 2;
            }
        }
        return sum;
    }
};