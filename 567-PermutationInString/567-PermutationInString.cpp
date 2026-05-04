// Last updated: 04/05/2026, 15:43:00
class Solution {
public:
    // Helper function to compare two frequency arrays
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // Frequency array for s1
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();
        int s2Len = s2.length();

        // Sliding window frequency array
        int windFreq[26] = {0};

        // Fill initial window
        for (int i = 0; i < min(windSize, s2Len); i++) {
            windFreq[s2[i] - 'a']++;
        }

        // Check the first window
        if (isFreqSame(freq, windFreq)) {
            return true;
        }

        // Slide the window across s2
        for (int i = windSize; i < s2Len; i++) {
            // Add the next character in the window
            windFreq[s2[i] - 'a']++;

            // Remove the first character of the previous window
            windFreq[s2[i - windSize] - 'a']--;

            // Check the updated window
            if (isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }
};
