// Last updated: 06/07/2026, 09:53:20
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0, j = n - 1;
        int count = 0;

        while(i < j){
            if(nums[i]+nums[j] == k){
                count++;
                i++;
                j--;
            } else if (nums[i]+nums[j] < k) {
                i++;
            } else {
                j--;
            }
            
        }
        return count;
    }
};