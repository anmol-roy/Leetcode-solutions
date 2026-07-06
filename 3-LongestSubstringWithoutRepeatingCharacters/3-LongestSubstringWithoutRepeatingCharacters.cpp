// Last updated: 06/07/2026, 09:55:02
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int left = 0;
        
        // Array to store the count of characters in the current window
        // Size 128 covers all standard ASCII characters (letters, numbers, symbols)
        vector<int> charCount(128, 0);

        // 'right' expands the window boundary to the right
        for (int right = 0; right < n; right++) {
            // Add the incoming character to our current window count
            charCount[s[right]]++;

            // If a character count goes above 1, we have a duplicate!
            // Shrink the window from the left until the duplicate is gone.
            while (charCount[s[right]] > 1) {
                charCount[s[left]]--;
                left++;
            }

            // Calculate the current window size and track the maximum
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
