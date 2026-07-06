// Last updated: 06/07/2026, 09:54:06
class Solution {
    bool fun(unordered_map<char, int>& have, unordered_map<char, int>& need) {
        for (auto it : need) {
            char ch = it.first;
            int countNeeded = it.second;
            
            if (have[ch] < countNeeded) {
                return false;
            }
        }
        return true;
    }

public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need; 
        unordered_map<char, int> have; 

        for (auto it : ransomNote) {
            need[it]++;
        }
        for (auto it : magazine) {
            have[it]++;
        }
        
        return fun(have, need);
    }
};
