// Last updated: 03/10/2026, 23:49:41
class Solution {
public:
    int maximumLengthSubstring(string s) {
         unordered_map<char, int> m;
        int i = 0, j = 0, n = s.size();
        int res = 0;    
        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 2) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};