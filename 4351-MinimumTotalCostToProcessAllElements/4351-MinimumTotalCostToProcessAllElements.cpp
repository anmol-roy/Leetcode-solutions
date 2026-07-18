// Last updated: 19/07/2026, 00:22:37
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long res = k;
        long long operations = 0;
        long long ans = 0;
        for(long long x : nums) {
            if(res < x) {
                long long need = (x - res + k - 1) / k;
                __int128 cost = (__int128)need * (2 * (operations + 1) + (need - 1)) / 2;
                ans = (ans + cost) % MOD;
                operations += need;
                res += need * 1LL * k;
            }
            res -= x;
        }
        return ans % MOD;
     }
};