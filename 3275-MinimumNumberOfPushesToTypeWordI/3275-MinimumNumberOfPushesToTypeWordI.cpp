// Last updated: 02/08/2026, 08:57:25
class Solution {
public:
    int minimumPushes(string word) {

        vector<int> fq(26, 0);

        for(char it : word) {
            fq[it - 'a']++;
        }
        sort(fq.begin(),fq.end(), greater<int>());

        int ans = 0;
        for(int i = 0; i < 26; i++){
            int pushes = (i / 8) + 1;
            ans += fq[i] * pushes;
        }
        return ans;
    }
};