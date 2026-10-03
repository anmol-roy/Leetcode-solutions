// Last updated: 03/10/2026, 23:53:42
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector <int> res(n);
        int prefix = 0;
        for(int i = 0; i < n; i++) {
            res[i] = prefix + nums[i];
            prefix += nums[i];
        }
        return res;
    }
};