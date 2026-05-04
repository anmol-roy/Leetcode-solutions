// Last updated: 04/05/2026, 15:43:15
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int res = 0;
       int n = nums.size();
       
       // XOR all numbers from 0 to n
       for(int i = 0; i <= n; i++) {
            res ^= i;
       } 
       for(int it: nums) {
            res ^= it;
       } 
       return res;
    }
};