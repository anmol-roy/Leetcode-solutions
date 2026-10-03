// Last updated: 03/10/2026, 23:53:00
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