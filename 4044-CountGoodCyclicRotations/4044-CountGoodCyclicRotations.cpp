// Last updated: 03/10/2026, 23:45:05
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int count = 0;
        int half = n / 2;
        long long totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        long long firstHalfSum = 0;
        for (int i = 0; i < half; i++) {
            firstHalfSum += nums[i];
        }
        if (firstHalfSum > totalSum - firstHalfSum) {
            count++;
        }

        
        for (int rotation = 1; rotation < n; rotation++) {
            
            firstHalfSum -= nums[(rotation - 1)];
            firstHalfSum += nums[(rotation + half -  1) % n];
            if (firstHalfSum > totalSum - firstHalfSum) count++;
        }
        return count++;
    }
};