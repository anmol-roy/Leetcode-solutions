// Last updated: 06/07/2026, 09:54:04
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int> f;
        for(auto it: s){
            f[it]++;
        }
        for(int i = 0; i < n; i++){
            if(f[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};