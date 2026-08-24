// Last updated: 24/08/2026, 19:57:24
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> zeros(n, 0);

        if(nums == zeros) {
            return 0;
        }

        int x = 0;

        for ( int num : nums) {
            x ^= num;
        }

        return x ? n : n - 1;
    }
};