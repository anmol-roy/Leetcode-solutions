// Last updated: 09/07/2026, 16:33:54
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> lastIndex;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int left = 0;
        long long maxSum = 0;

        for (int right = 0; right < n; right++) {

            if (lastIndex.count(nums[right]) &&
                lastIndex[nums[right]] >= left) {

                left = lastIndex[nums[right]] + 1;
            }

            lastIndex[nums[right]] = right;

            long long currentSum =
                prefix[right + 1] - prefix[left];

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};