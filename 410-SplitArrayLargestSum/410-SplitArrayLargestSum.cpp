// Last updated: 04/08/2026, 18:33:18
class Solution {
bool largSum(vector<int>& nums, int k, int mid) {
    int partitions = 1;
    int sum = 0;
    for(int num : nums) {
        if ( sum + num <= mid) {
            sum+= num;
        } else {
            partitions++;
            sum = num;
        } 
        if (partitions > k) {
            return false;
        }
    }  
    return true;
}

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high) {
            int mid = low + ( high - low ) / 2;
            if (largSum(nums, k, mid) ) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        return low;
    }
};