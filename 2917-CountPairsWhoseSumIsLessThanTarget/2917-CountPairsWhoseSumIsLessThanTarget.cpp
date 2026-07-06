// Last updated: 06/07/2026, 09:52:41
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;

        sort(nums.begin(), nums.end());
        int left = 0; 
        int right = nums.size()-1;

        while(left < right){
            if(nums[left] + nums[right] < target){
                count += right - left;
                left++;
            }
            else {
                right--;
            }
        }
        return count;
    }
};