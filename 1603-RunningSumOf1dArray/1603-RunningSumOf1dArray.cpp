// Last updated: 09/07/2026, 16:33:58
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