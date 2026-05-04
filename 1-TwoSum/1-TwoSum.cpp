// Last updated: 04/05/2026, 15:45:00
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; 

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 

            if (hashmap.find(complement) != hashmap.end()) {
                return {hashmap[complement], i}; 
            }

            hashmap[nums[i]] = i;
        }

        return {}; 
    }
};
