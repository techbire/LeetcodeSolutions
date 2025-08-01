class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if (numRows == 0)
            return result;

        result.push_back({1}); // First row

        for (int i = 1; i < numRows; ++i) {
            vector<int> prevRow = result[i - 1];
            vector<int> row;
            row.push_back(1); // Start with 1

            for (int j = 0; j < i - 1; ++j) {
                row.push_back(prevRow[j] + prevRow[j + 1]);
            }

            row.push_back(1); // End with 1
            result.push_back(row);
        }

        return result;
    }
};