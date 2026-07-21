// Last updated: 21/07/2026, 23:37:52
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
         int sumStart = (start[0] + start[1]) % 2;
        int sumTarget = (target[0] + target[1]) % 2;
        return sumStart == sumTarget;
    }
};
