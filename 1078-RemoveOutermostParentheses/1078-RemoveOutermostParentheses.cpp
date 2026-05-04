// Last updated: 04/05/2026, 15:42:46
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int counter = 0;
        int i =0;
        for (char c : s) {
            if (c == '(') {
            if (counter > 0) ans += c; 
                counter++;
            } else {
                counter--;
            if (counter > 0) ans += c; 
            }
        }
        return ans;
    }
};