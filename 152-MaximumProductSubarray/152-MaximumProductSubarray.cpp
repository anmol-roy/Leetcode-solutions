// Last updated: 04/05/2026, 15:43:55
// 18/04/2006

// 18/04/2006

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < n; i++) {
            // If negative, the max and min will swap roles
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};
