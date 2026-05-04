// Last updated: 04/05/2026, 15:43:02
// 20/04/26
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSumCount;
        preSumCount[0] = 1; // Base case: a sum of 0 has occurred once
        
        int currentSum = 0;
        int totalSubarrays = 0;

        for (int x : nums) {
            currentSum += x;

            // If (currentSum - k) exists, it means a subarray 
            // ending here sums to k. Add its frequency to our count.
            if (preSumCount.find(currentSum - k) != preSumCount.end()) {
                totalSubarrays += preSumCount[currentSum - k];
            }

            // Store the frequency of the current prefix sum
            preSumCount[currentSum]++;
        }

        return totalSubarrays;
    }
};
