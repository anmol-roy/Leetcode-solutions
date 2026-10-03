// Last updated: 03/10/2026, 23:56:04
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long curr = 0;

        for (int i = n - 1; i >= 0; i--) {
            curr = (curr + shifts[i]) % 26; 
            s[i] = 'a' + (s[i] - 'a' + curr) % 26;
        }

        return s;
    }
};
