// Last updated: 04/05/2026, 15:43:30
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSize = INT_MAX;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            currentSum += nums[right];

            while (currentSum >= target) {
                minSize = min(minSize, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return (minSize == INT_MAX) ? 0 : minSize;
    }
};
