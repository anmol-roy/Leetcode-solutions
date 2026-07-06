// Last updated: 06/07/2026, 09:53:23
class Solution {
    bool isVowel(char ch) {
        ch = toupper(ch);
        return (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
public:
    int maxVowels(string s, int k) {

        int n = s.size();
        int count = 0;

        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int maxVowel = count;

        for(int i = k; i < n; i++){
            // 1. Add the incoming character from the right
            if (isVowel(s[i])) {
                count++;
            }

            // 2. Remove the outgoing character from the left
            if (isVowel(s[i - k])) {
                count--;
            }

            // 3. Keep track of the maximum vowels found in any window
            maxVowel = max(maxVowel, count);
        }

        return maxVowel;
    }
};