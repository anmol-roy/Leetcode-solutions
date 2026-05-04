// Last updated: 04/05/2026, 15:42:52
class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i; 
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
