// Last updated: 04/05/2026, 15:44:06
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int i : nums) {
        result = result ^ i;
    }  
    return result;
    }
};