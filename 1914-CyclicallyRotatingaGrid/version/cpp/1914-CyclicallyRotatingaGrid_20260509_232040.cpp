// Last updated: 09/05/2026, 23:20:40
1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int numLayers = min(m, n) / 2;
7
8        for (int layer = 0; layer < numLayers; ++layer) {
9            vector<int> elements;
10            int top = layer, bottom = m - 1 - layer;
11            int left = layer, right = n - 1 - layer;
12
13            // 1. Extract elements from the current layer (counter-clockwise)
14            for (int j = left; j < right; ++j) elements.push_back(grid[top][j]);      // Top row
15            for (int i = top; i < bottom; ++i) elements.push_back(grid[i][right]);   // Right column
16            for (int j = right; j > left; --j) elements.push_back(grid[bottom][j]);  // Bottom row
17            for (int i = bottom; i > top; --i) elements.push_back(grid[i][left]);    // Left column
18
19            // 2. Rotate the extracted 1D vector
20            int size = elements.size();
21            int rotations = k % size;
22            // std::rotate shifts elements to the left by 'rotations' steps
23            rotate(elements.begin(), elements.begin() + rotations, elements.end());
24
25            // 3. Put the rotated elements back into the grid
26            int idx = 0;
27            for (int j = left; j < right; ++j) grid[top][j] = elements[idx++];
28            for (int i = top; i < bottom; ++i) grid[i][right] = elements[idx++];
29            for (int j = right; j > left; --j) grid[bottom][j] = elements[idx++];
30            for (int i = bottom; i > top; --i) grid[i][left] = elements[idx++];
31        }
32
33        return grid;
34    }
35};
36