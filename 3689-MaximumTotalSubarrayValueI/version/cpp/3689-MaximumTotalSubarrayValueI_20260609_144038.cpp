// Last updated: 09/06/2026, 14:40:38
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int n = nums.size();
5        int maxi = INT_MIN;
6        int mini = INT_MAX;
7
8        for(int &num : nums) {
9            maxi = max(maxi, num);
10            mini = min(mini, num);
11
12        }
13        return 1l * k * (maxi - mini);
14    }
15};