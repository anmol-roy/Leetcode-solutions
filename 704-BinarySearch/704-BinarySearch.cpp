// Last updated: 03/10/2026, 23:56:27
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            // int  m = (l + r) / 2;
            int m = l + (r - l) / 2; 
            if (target == nums[m]) {
                return m;
            }
            else if ( target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};