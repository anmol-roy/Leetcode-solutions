// Last updated: 24/08/2026, 20:01:44
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> lastSeen;

        for (int i = 0; i < n; i++) {
            int currentSeen = nums[i];
            if(lastSeen.count(currentSeen)) {
                if (i - lastSeen[currentSeen] <= k) {
                    return true;
                }
            }
            lastSeen[currentSeen] = i;
        }


       


        return false;
    }
};