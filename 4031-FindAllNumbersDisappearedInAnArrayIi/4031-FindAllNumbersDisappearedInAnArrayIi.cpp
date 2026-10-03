// Last updated: 03/10/2026, 23:45:19
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        long long start = lower;
        for (int num: nums) {
            if (num < lower || num > upper) {
                continue;
            }
            if (num > start) {
                ans.push_back({(int)(start),(num - 1)});
            }
            start = (long long)num + 1;
            
        }
        if (start <= upper) {
                ans.push_back({(int)(start ), upper});
        }
        return ans;
    }
};