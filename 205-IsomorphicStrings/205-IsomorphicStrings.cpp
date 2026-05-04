// Last updated: 04/05/2026, 15:43:33
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Size 256 covers all standard ASCII characters
        int mapS[256] = {0}; 
        int mapT[256] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            // Check if the last seen index for both characters is the same
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            
            // Store current index + 1 (to distinguish from the default 0)
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        
        return true;
    }
};
