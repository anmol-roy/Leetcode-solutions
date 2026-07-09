// Last updated: 09/07/2026, 16:32:27
1class Solution {
2public:
3    string shiftingLetters(string s, vector<int>& shifts) {
4        int n = s.size();
5        long long curr = 0;
6
7        for (int i = n - 1; i >= 0; i--) {
8            curr = (curr + shifts[i]) % 26; 
9            s[i] = 'a' + (s[i] - 'a' + curr) % 26;
10        }
11
12        return s;
13    }
14};
15