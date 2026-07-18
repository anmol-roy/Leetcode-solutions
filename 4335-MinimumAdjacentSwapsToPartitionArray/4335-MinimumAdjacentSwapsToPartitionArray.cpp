// Last updated: 19/07/2026, 00:22:35

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
  
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> label(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] < a) label[i] = 0;
            else if (nums[i] <= b) label[i] = 1;
            else label[i] = 2;
        }

        long long count0 = 0, count1 = 0, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (label[i] == 2) {
                ans = (ans + count0 + count1) % MOD;
            } else if (label[i] == 1) {
                ans = (ans + count0) % MOD;
            }

            if (label[i] == 0) count0++;
            else if (label[i] == 1) count1++;
        }

        return (int) ans;
    }
};