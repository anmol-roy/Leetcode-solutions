// Last updated: 12/07/2026, 09:07:03
1class Solution {
2public:
3    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<int> dp(n, 1);
8        int ans = 1;
9
10        for(int i =0; i< n; i++) {
11            for(int j = 0; j < i; j++) {
12                bool ok = true;
13                for(int r = 0; r < m; r++) {
14                    if(abs(grid[r][i] - grid[r][j]) > limit) {
15                        ok = false;
16                        break;
17                    }
18                }
19                if (ok) {
20                    dp[i] = max(dp[i] , dp[j] + 1);
21                }
22                
23            }
24            ans = max(ans, dp[i]);
25        }
26        return ans;
27    }
28};