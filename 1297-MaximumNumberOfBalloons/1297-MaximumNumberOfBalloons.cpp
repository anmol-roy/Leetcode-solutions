// Last updated: 06/07/2026, 09:53:32
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;
        
        // Define what we need for the word "balloon"
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;
        
        for (char c : text) {
            have[c]++;
        }
        
        int res = INT_MAX; 
        
        for (auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c]; 
            
            int times = fhave / fneed;
            res = min(res, times);
        }
        
        return res;
    }
};
