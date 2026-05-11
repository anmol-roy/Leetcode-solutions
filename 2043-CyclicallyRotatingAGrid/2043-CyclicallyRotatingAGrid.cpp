// Last updated: 11/05/2026, 18:00:49
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int layer = 0; layer < numLayers; ++layer) {
            vector<int> elements;
            int top = layer, bottom = m - 1 - layer;
            int left = layer, right = n - 1 - layer;

            // 1. Extract elements from the current layer (counter-clockwise)
            for (int j = left; j < right; ++j) elements.push_back(grid[top][j]);      // Top row
            for (int i = top; i < bottom; ++i) elements.push_back(grid[i][right]);   // Right column
            for (int j = right; j > left; --j) elements.push_back(grid[bottom][j]);  // Bottom row
            for (int i = bottom; i > top; --i) elements.push_back(grid[i][left]);    // Left column

            // 2. Rotate the extracted 1D vector
            int size = elements.size();
            int rotations = k % size;
            // std::rotate shifts elements to the left by 'rotations' steps
            rotate(elements.begin(), elements.begin() + rotations, elements.end());

            // 3. Put the rotated elements back into the grid
            int idx = 0;
            for (int j = left; j < right; ++j) grid[top][j] = elements[idx++];
            for (int i = top; i < bottom; ++i) grid[i][right] = elements[idx++];
            for (int j = right; j > left; --j) grid[bottom][j] = elements[idx++];
            for (int i = bottom; i > top; --i) grid[i][left] = elements[idx++];
        }

        return grid;
    }
};
