// Last updated: 04/05/2026, 15:42:29
class Solution {
public:
    string largestOddNumber(string num) {
        // Step 1: Start from the back (right to left)
        for (int i = num.length() - 1; i >= 0; i--) {
            
            // Step 2: Check if the character is an odd digit
            // (num[i] - '0') converts the character to an integer
            if ((num[i] - '0') % 2 != 0) {
                
                // Step 3: Return the substring from the start to this digit
                return num.substr(0, i + 1);
            }
        }
        
        // Step 4: If no odd digit is found, return empty string
        return "";
    }
};
