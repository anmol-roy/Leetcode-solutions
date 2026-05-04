// Last updated: 04/05/2026, 15:44:46
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int left = 0;
        int right = 1;
        while(right < n){
            if(nums[left] != nums[right]) {
                left++;
                nums[left] = nums[right];
            }
                right++;
            
        }
        return left+1;
    }
};