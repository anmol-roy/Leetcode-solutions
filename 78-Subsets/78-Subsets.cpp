// Last updated: 04/05/2026, 15:44:26
class Solution {
public:
    void backtrack(int ind, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if we've considered all elements
        if (ind == nums.size()) {
            result.push_back(current);
            return;
        }

        // Option 1: Don't include nums[ind] (Exclude)
        backtrack(ind + 1, nums, current, result);

        // Option 2: Include nums[ind] (Include)
        current.push_back(nums[ind]);
        backtrack(ind + 1, nums, current, result);
        
        // Backtrack: remove the element to restore state for other recursive calls
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};
