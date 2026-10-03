// Last updated: 03/10/2026, 23:45:06
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, pair<int, int>> ranges;
        for (int i = 0; i < n; i++) {
            if (ranges.find(nums[i]) == ranges.end()) {
                ranges[nums[i]] = {i, i};
            } else {
                ranges[nums[i]].second = i;
            }
        }
        int ans= 0; 
        for (auto & [x, range] : ranges) {
            bool isConsecutive = true;
            for (int i = range.first; i <= range.second; i++) {
                 if (nums[i] != x) {
                     isConsecutive = false;
                        break;
                 }
            }
            if(isConsecutive) ans++;
        }
        return ans;
    }
};