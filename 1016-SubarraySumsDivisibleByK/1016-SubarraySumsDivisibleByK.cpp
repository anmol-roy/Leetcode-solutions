// Last updated: 04/05/2026, 15:42:49
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        // Frequency array to store counts of each remainder (0 to k-1)
        // Using a vector since we know the range of remainders is [0, k-1]
        std::vector<int> count(k, 0);
        
        // Initialize with remainder 0 having count 1 to handle subarrays 
        // starting from index 0 that are already divisible by k
        count[0] = 1;
        
        int prefix_sum = 0;
        int result = 0;
        
        for (int num : nums) {
            // Update prefix sum and find its remainder
            // Using ((prefix_sum + num) % k + k) % k handles negative numbers in C++
            prefix_sum = ((prefix_sum + num) % k + k) % k;
            
            // If this remainder has been seen before, it means there are
            // subarrays ending here with a sum divisible by k
            result += count[prefix_sum];
            
            // Increment the frequency of the current remainder
            count[prefix_sum]++;
        }
        
        return result;
    }
};
