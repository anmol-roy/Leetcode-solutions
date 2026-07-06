// Last updated: 06/07/2026, 09:53:57
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int maxSeen = nums[0];
        int minSeen = nums[n-1];

        for(int i = 1, j = n - 2; i < n; i++, j--){
            maxSeen = max(maxSeen , nums[i]);
            if(nums[i] < maxSeen){
                right = i;
            }

            minSeen = min(minSeen ,nums[j]);
            if(nums[j] > minSeen){
                left = j;
            }
        }

        if(right == -1) return 0;
        return right-left + 1;
    }
};