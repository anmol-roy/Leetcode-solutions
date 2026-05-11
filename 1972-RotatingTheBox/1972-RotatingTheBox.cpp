// Last updated: 11/05/2026, 18:00:54
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        // 1. Create a new matrix for the 90-degree rotation
        // Dimensions change from m x n to n x m
        vector<vector<char>> result(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = box[i][j];
            }
        }

        // 2. Apply Gravity (using your logic from the image)
        // Now acting vertically on the 'result' matrix
        for (int j = 0; j < m; j++) {
            int spaceBottomRow = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '*') {
                    spaceBottomRow = i - 1;
                    continue;
                }
                
                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[spaceBottomRow][j] = '#';
                    spaceBottomRow--;
                }
            }
        }
        
        return result;
    }
};
