// Last updated: 03/10/2026, 23:49:56
class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> frq(26, 0);
        for(char ch : word) {
            frq[ch - 'a']++;
        }
        
        sort(frq.begin(), frq.end());
        
        int minPushing = 0;
        int distinctCharCount = 0;
        
        for(int i = 25; i >= 0; i--) {
            if (frq[i] == 0) break; 
            
            int pushCnt = (distinctCharCount / 8) + 1;
            
            minPushing += frq[i] * pushCnt;
            distinctCharCount++;
        }
        
        return minPushing;
    }
};
