// Last updated: 06/07/2026, 09:54:10
class Solution {
bool isVowel(char c) {
    // Convert to lowercase first to handle both 'A' and 'a'
    switch (tolower(c)) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            if(!isVowel(s[i])){
                i++;
            }
            if(!isVowel(s[j])) {
                j--;
            }
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};