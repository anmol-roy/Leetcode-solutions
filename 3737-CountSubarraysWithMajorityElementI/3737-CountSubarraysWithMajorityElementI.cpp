// Last updated: 03/10/2026, 23:46:43
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;

        for (int l = 0; l < n; l++) {
            int targetCount = 0;

            for (int r = l; r < n; r++) {
                if (nums[r] == target) {
                    targetCount++;
                }

                int len = r - l + 1;

                if (targetCount > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};