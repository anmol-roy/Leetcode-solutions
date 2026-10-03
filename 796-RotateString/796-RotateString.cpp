// Last updated: 03/10/2026, 23:56:20
class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) return false;
        
        // Check if 'goal' exists inside 's + s'
        return (s + s).find(goal) != string::npos;
    }
};