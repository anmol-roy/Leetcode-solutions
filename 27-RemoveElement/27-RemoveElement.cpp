// Last updated: 04/05/2026, 15:44:44
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int i = 0;
        int n = nums.size();
        while(i < n){
            if(nums[i] != val){
                swap(nums[i],nums[k]);
                i++;
                k++;
            } else {
                i++;
            }
        }
        return k;
    }
};