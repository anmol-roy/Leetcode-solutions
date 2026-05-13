// Last updated: 13/05/2026, 21:48:18
1
2class Solution {
3public:
4    int minMoves(vector<int>& nums, int limit) {
5        int n = nums.size();
6       vector<int> d(2 * limit + 2, 0);
7        
8        for (int i = 0; i < n / 2; ++i) {
9            int a = min(nums[i], nums[n - 1 - i]);
10            int b = max(nums[i], nums[n - 1 - i]);
11            
12            d[a + 1] -= 1;
13            d[a + b] -= 1;
14            d[a + b + 1] += 1;
15            d[b + limit + 1] += 1;
16        }
17        
18        int min_ops = n;
19        int current_ops = n;
20        
21        for (int sign_sum = 2; sign_sum <= 2 * limit; ++sign_sum) {
22            current_ops += d[sign_sum];
23            min_ops = min(min_ops, current_ops);
24        }
25        
26        return min_ops;
27    }
28};
29