class Solution {
public:

 
    bool isSafe(int col, vector<int>& board) {
        int row = board.size(); // current row
        for (int prevRow = 0; prevRow < row; prevRow++) {
            // Same column
            if (board[prevRow] == col)
                return false;
            // Same diagonal
            if (abs(row - prevRow) == abs(col - board[prevRow]))
                return false;
        }
        return true;
    }

    void solve(vector<int>& board, vector<vector<int>>& solutions, int n) {

        // All queens placed
        if (board.size() == n) {
            solutions.push_back(board);
            return;
        }
        // Try placing queen in every column of current row
        for (int col = 0; col < n; col++) {

            if (isSafe(col, board)) {
                board.push_back(col);     // Place queen
                solve(board, solutions, n);
                board.pop_back();         // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<int> board;                 // board[row] = column of queen
        vector<vector<int>> solutions;
        solve(board, solutions, n);
        vector<vector<string>> ans;
        // Convert column positions into required board format
        for (auto& solution : solutions) {
            vector<string> chessBoard;
            for (int col : solution) {
                string row(n, '.');
                row[col] = 'Q';
                chessBoard.push_back(row);
            }
            ans.push_back(chessBoard);
        }

        return ans;
    }
};