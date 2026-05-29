// Last updated: 29/05/2026, 22:14:12
1class Solution {
2public:
3    int minElement(vector<int>& nums) {
4        int res = 36;
5        for (auto& n : nums)
6            res = min(res, n - 9 * ((n/10) + (n/100) + (n/1000) + (n/10000)));
7        
8        return res;
9    }
10};