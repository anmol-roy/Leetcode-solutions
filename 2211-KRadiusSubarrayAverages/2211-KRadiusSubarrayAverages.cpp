// Last updated: 06/07/2026, 09:53:03
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> res (n, -1);
        int windowSize = 2 * k + 1;

        if (n < windowSize) {
            return res;
        }

        long long windowSum = 0;

        for (int i = 0; i < windowSize; i++) {
            windowSum += nums[i];
        }

        res[k] = windowSum / windowSize;

        for (int i = windowSize; i < n; i++) {
            windowSum += nums[i] - nums[i - windowSize];
            res[i - k] = windowSum / windowSize;
        }

        return res;
    }
};
