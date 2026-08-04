// Last updated: 04/08/2026, 18:33:42
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int row = 0;
        int col = cols - 1;

        while (row < rows && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] > target)
                col--;      // Move left
            else
                row++;      // Move down
        }

        return false;
    }
};