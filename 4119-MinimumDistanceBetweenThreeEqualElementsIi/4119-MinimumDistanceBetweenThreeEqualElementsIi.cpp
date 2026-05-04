// Last updated: 04/05/2026, 15:42:30

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        // Map to store a list of indices for each unique number
        unordered_map<int, vector<int>> mp;
        int min_dist = INT_MAX;

        for (int k = 0; k < n; ++k) {
            mp[nums[k]].push_back(k);
            
            // If we have at least 3 occurrences of the current number
            if (mp[nums[k]].size() >= 3) {
                const vector<int>& indices = mp[nums[k]];
                int m = indices.size();
                
                // For indices i < j < k, the distance is 2 * (k - i)
                // i is at indices[m-3], k is the current index k
                int current_dist = 2 * (k - indices[m - 3]);
                min_dist = min(min_dist, current_dist);
            }
        }

        // Return -1 if no good tuple was found
        return (min_dist == INT_MAX) ? -1 : min_dist;
    }
};
