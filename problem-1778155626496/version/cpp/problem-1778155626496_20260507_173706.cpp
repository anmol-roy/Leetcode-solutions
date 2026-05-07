// Last updated: 07/05/2026, 17:37:06
1class Solution {
2public:
3    vector<int> maxValue(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        vector<int> preMax(n);
7        
8        // Step 1: Precompute the maximum value from the left up to each index
9        preMax[0] = nums[0];
10        for (int i = 1; i < n; ++i) {
11            preMax[i] = max(preMax[i - 1], nums[i]);
12        }
13        
14        // Step 2: Traverse backwards to find the maximum reachable value
15        int sufMin = 1e9 + 7; // Representing infinity
16        for (int i = n - 1; i >= 0; --i) {
17            // If we can jump forward to a smaller value that eventually jumps back
18            // to a higher value, we take the result from the next index.
19            if (preMax[i] > sufMin) {
20                ans[i] = ans[i + 1];
21            } else {
22                ans[i] = preMax[i];
23            }
24            // Update the minimum value seen from the right
25            sufMin = min(sufMin, nums[i]);
26        }
27        
28        return ans;
29    }
30};
31