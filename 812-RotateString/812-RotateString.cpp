// Last updated: 04/05/2026, 15:43:19
class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) return false;
        
        // Check if 'goal' exists inside 's + s'
        return (s + s).find(goal) != string::npos;
    }
};