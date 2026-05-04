// Last updated: 04/05/2026, 15:42:38
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Use modulo (%) to compare the last element with the first element
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // Optimization: If more than 1 break is found, it can't be sorted and rotated
            if (count > 1) {
                return false;
            }
        }

        // Return true if there is 0 or 1 break point
        return true;
    }
};
