// Last updated: 06/07/2026, 09:52:10
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int &num : nums) {
            maxi = max(maxi, num);
            mini = min(mini, num);

        }
        return 1l * k * (maxi - mini);
    }
};