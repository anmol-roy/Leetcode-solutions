// Last updated: 03/10/2026, 23:45:39
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