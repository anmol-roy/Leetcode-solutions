// Last updated: 03/10/2026, 23:52:51
// 18/04/2006
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEndingHere = 0;
        int minEndingHere = 0;
        int maxAbsSum = 0;
        
        for (int x : nums) {
            // Standard Kadane's to find max positive sum
            maxEndingHere = max(x, maxEndingHere + x);
            // Standard Kadane's to find min negative sum
            minEndingHere = min(x, minEndingHere + x);
            // The answer is the best we've seen from either extreme
            maxAbsSum = max({maxAbsSum, maxEndingHere, abs(minEndingHere)});
        }
        
        return maxAbsSum;
    }
};
