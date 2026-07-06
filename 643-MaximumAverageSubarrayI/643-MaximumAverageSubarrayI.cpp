// Last updated: 06/07/2026, 09:53:54
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;
        long long currentSum = 0;
        
        for(int i = 0; i < k; i++){
            currentSum += nums[i];
        }
        
        long long maxSum = currentSum;
        for(int i = k; i < n; i++){
            currentSum += nums[i] - nums[i-k];
            maxSum = max(currentSum, maxSum);
        }
        
        return (double)maxSum / k; 
    }
};