// Last updated: 11/05/2026, 18:00:44
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> preMax(n);
        
        // Step 1: Precompute the maximum value from the left up to each index
        preMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i - 1], nums[i]);
        }
        
        // Step 2: Traverse backwards to find the maximum reachable value
        int sufMin = 1e9 + 7; // Representing infinity
        for (int i = n - 1; i >= 0; --i) {
            // If we can jump forward to a smaller value that eventually jumps back
            // to a higher value, we take the result from the next index.
            if (preMax[i] > sufMin) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = preMax[i];
            }
            // Update the minimum value seen from the right
            sufMin = min(sufMin, nums[i]);
        }
        
        return ans;
    }
};
