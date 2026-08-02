// Last updated: 02/08/2026, 08:59:47
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;  // Tracks closing brackets that lack a pair
        int close_needed = 0; // Tracks opening brackets that lack a pair

        for (char ch : s) {
            if (ch == '(') {
                close_needed++; // We need a ')' to balance this
            } else { // ch == ')'
                if (close_needed > 0) {
                    close_needed--; // Balanced an existing '('
                } else {
                    open_needed++; // No '(' available, we must add one later
                }
            }
        }
        return open_needed + close_needed;
    }
};
