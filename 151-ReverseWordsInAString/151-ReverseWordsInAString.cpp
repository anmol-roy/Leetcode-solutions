// Last updated: 04/05/2026, 15:43:56
class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int left = 0;  // pointer for where the next character goes
        int i = 0;     // pointer to traverse the original string

        while (i < n) {
            if (s[i] != ' ') {
                // Add a space before the next word (except the first one)
                if (left != 0) s[left++] = ' ';

                // Find the end of the current word
                int start = left;
                while (i < n && s[i] != ' ') {
                    s[left++] = s[i++];
                }

                // 2. Reverse the word we just placed to fix character order
                reverse(s.begin() + start, s.begin() + left);
            }
            i++;
        }

        // 3. Trim the extra characters at the end
        s.erase(s.begin() + left, s.end());
        return s;
    }
};
