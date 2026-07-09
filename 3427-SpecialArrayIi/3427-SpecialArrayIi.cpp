// Last updated: 09/07/2026, 16:33:28
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);
        
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2) {
                pref[i]++;
            }
        }
        
        vector<bool> ans;
        for (auto& q : queries) {
            int from = q[0];
            int to = q[1];
            
          
            if (pref[to] - pref[from] == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};
