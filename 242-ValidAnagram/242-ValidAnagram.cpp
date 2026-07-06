// Last updated: 06/07/2026, 09:54:14
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        if (s.length() != t.length()) return false;

        for(int i = 0; i < s.length(); i++){
            countS[s[i]]++;
            countT[t[i]]++;
        }
        
        return countS == countT;
    }
};