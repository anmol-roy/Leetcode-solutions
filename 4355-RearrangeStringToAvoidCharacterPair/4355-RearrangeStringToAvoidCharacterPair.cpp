// Last updated: 19/07/2026, 00:22:38
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector <int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;

        string ans;

        for(char c = 'a'; c <= 'z'; c++) {
            if(c == x || c == y) continue;

            ans.append(freq[c - 'a'], c);
        }
        ans.append(freq[y - 'a'], y);
        ans.append(freq[x - 'a'], x);

        return ans;
        
    }
};