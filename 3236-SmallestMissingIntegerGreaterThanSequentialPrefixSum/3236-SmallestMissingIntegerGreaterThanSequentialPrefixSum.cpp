// Last updated: 24/08/2026, 19:58:43
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
                continue;
            }
            break;
        }
        
        unordered_set<int> hashset;
        for(int i : nums) {
            hashset.insert(i); 
        }

        while (hashset.contains(sum)) {
            sum++;
        }
        return sum;
    }
};
