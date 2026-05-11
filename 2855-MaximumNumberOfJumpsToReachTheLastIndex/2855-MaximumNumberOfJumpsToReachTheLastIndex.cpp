// Last updated: 11/05/2026, 18:00:47
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // Initialize DP array with -1 to indicate unreachable indices
        vector<int> dp(n, -1);
        
        // Base case: Starting at index 0 requires 0 jumps
        dp[0] = 0;

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if index i is reachable from index 0
                // and if the jump condition |nums[j] - nums[i]| <= target is met
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        // Return the max jumps to the last index, or -1 if unreachable
        return dp[n - 1];
    }
};
