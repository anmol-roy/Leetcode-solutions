// Last updated: 04/05/2026, 15:43:06
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;

        for(int it : nums) {
            if(it == 1) {
                currentCount++; 
                if(currentCount > maxCount) maxCount = currentCount; 
            } else {
                currentCount = 0; 
            }
        }
        return maxCount;
    }
};
