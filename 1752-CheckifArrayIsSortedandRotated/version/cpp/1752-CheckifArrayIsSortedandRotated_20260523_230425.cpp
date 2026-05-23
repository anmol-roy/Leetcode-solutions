// Last updated: 23/05/2026, 23:04:25
1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int n = nums.size();
5        int count = 0;
6
7        for (int i = 0; i < n; i++) {
8            // Use modulo (%) to compare the last element with the first element
9            if (nums[i] > nums[(i + 1) % n]) {
10                count++;
11            }
12            
13            // Optimization: If more than 1 break is found, it can't be sorted and rotated
14            if (count > 1) {
15                return false;
16            }
17        }
18
19        // Return true if there is 0 or 1 break point
20        return true;
21    }
22};
23