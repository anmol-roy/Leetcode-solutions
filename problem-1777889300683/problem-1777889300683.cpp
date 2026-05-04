// Last updated: 04/05/2026, 15:38:20
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n = matrix.size(); // Add this line to define n
5        
6        for (int i = 0; i < n / 2; i++) {
7            for (int j = i; j < n - i - 1; j++) {
8                int temp = matrix[i][j];
9                matrix[i][j] = matrix[n - 1 - j][i];
10                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
11                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
12                matrix[j][n - 1 - i] = temp;
13            }
14        }
15    }
16};
17