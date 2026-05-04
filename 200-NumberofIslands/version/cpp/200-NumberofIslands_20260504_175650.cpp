// Last updated: 04/05/2026, 17:56:50
1class Solution {
2public:
3    void dfs(vector<vector<char>>& grid, int r, int c) {
4        int rows = grid.size();
5        int cols = grid[0].size();
6
7        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
8            return;
9        }
10
11        grid[r][c] = '0';
12
13        dfs(grid, r + 1, c); // Down
14        dfs(grid, r - 1, c); // Up
15        dfs(grid, r, c + 1); // Right
16        dfs(grid, r, c - 1); // Left
17    }
18
19    int numIslands(vector<vector<char>>& grid) {
20        if (grid.empty()) return 0;
21
22        int num_islands = 0;
23        int rows = grid.size();
24        int cols = grid[0].size();
25
26        for (int r = 0; r < rows; ++r) {
27            for (int c = 0; c < cols; ++c) {
28                if (grid[r][c] == '1') {
29                    num_islands++;
30                    dfs(grid, r, c);
31                }
32            }
33        }
34
35        return num_islands;
36    }
37};
38