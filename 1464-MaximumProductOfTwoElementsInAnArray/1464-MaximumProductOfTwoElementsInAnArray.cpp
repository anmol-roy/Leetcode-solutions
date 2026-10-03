// Last updated: 03/10/2026, 23:53:45
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
       return (nums[n - 1] - 1) * (nums[n - 2] - 1);
        }
};