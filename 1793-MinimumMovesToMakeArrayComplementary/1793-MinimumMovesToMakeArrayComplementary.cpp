// Last updated: 21/05/2026, 18:33:21

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
       vector<int> d(2 * limit + 2, 0);
        
        for (int i = 0; i < n / 2; ++i) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);
            
            d[a + 1] -= 1;
            d[a + b] -= 1;
            d[a + b + 1] += 1;
            d[b + limit + 1] += 1;
        }
        
        int min_ops = n;
        int current_ops = n;
        
        for (int sign_sum = 2; sign_sum <= 2 * limit; ++sign_sum) {
            current_ops += d[sign_sum];
            min_ops = min(min_ops, current_ops);
        }
        
        return min_ops;
    }
};
