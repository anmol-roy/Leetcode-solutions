// Last updated: 03/10/2026, 23:54:08
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> freq(3, 0);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;

            while (freq[0] && freq[1] && freq[2]) {
                ans += (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};