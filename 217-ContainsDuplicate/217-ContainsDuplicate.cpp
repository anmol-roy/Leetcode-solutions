// Last updated: 06/07/2026, 09:54:21
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int > freq;
        for (auto it : nums){
            freq[it]++;
        }
        for ( auto it : freq) {
            if(it.second > 1){
                return true;
            }
        }
        return false;
    }
};