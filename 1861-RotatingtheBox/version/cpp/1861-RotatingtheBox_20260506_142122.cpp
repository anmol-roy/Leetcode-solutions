// Last updated: 06/05/2026, 14:21:22
1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
4        int m = box.size();
5        int n = box[0].size();
6        
7        // 1. Create a new matrix for the 90-degree rotation
8        // Dimensions change from m x n to n x m
9        vector<vector<char>> result(n, vector<char>(m));
10        for (int i = 0; i < m; i++) {
11            for (int j = 0; j < n; j++) {
12                result[j][m - 1 - i] = box[i][j];
13            }
14        }
15
16        // 2. Apply Gravity (using your logic from the image)
17        // Now acting vertically on the 'result' matrix
18        for (int j = 0; j < m; j++) {
19            int spaceBottomRow = n - 1;
20            for (int i = n - 1; i >= 0; i--) {
21                if (result[i][j] == '*') {
22                    spaceBottomRow = i - 1;
23                    continue;
24                }
25                
26                if (result[i][j] == '#') {
27                    result[i][j] = '.';
28                    result[spaceBottomRow][j] = '#';
29                    spaceBottomRow--;
30                }
31            }
32        }
33        
34        return result;
35    }
36};
37