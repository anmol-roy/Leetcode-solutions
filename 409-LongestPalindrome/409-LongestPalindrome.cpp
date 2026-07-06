// Last updated: 06/07/2026, 09:54:03
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (auto it : counts) {
            int count = it.second;
            length += (count / 2) * 2;
            
            if (count % 2 != 0) {
                hasOdd = true;
            }
        }
        
        if (hasOdd) {
            length += 1;
        }
        
        return length;
    }
};
