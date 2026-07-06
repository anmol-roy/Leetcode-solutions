// Last updated: 06/07/2026, 09:54:01
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int m = s.size();
        int n = p.size();

        // Base Case
        if (n > m)
            return res;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Build First Window
        for (int i = 0; i < n; i++) {
            freq1[s[i] - 'a']++;
            freq2[p[i] - 'a']++;
        }

        // Check First Window
        if (freq1 == freq2)
            res.push_back(0);

        // Slide Window
        for (int i = n; i < m; i++) {

            // Add incoming character
            freq1[s[i] - 'a']++;

            // Remove outgoing character
            freq1[s[i - n] - 'a']--;

            // Compare frequencies
            if (freq1 == freq2)
                res.push_back(i - n + 1);
        }

        return res;
    }
};