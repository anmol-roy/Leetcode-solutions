// Last updated: 06/07/2026, 09:53:38
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxCount = 0;
        int zerocount = 0;
        int start = 0;

        for(int end = 0; end < nums.size(); end++) {
            if(nums[end] == 0) {
                zerocount++; 
            }
            
            while(zerocount > k){
                if(nums[start] == 0){
                    zerocount--;
                }
                start++;
            }
            
            maxCount = max(maxCount, (end - start) + 1);
        }
        return maxCount;
    }
};
