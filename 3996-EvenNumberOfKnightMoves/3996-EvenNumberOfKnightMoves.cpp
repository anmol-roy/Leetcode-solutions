// Last updated: 03/10/2026, 23:45:27
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
         int sumStart = (start[0] + start[1]) % 2;
        int sumTarget = (target[0] + target[1]) % 2;
        return sumStart == sumTarget;
    }
};
