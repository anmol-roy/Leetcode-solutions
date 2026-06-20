// Last updated: 20/06/2026, 10:05:34
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        unordered_map<char, int> countS;
5        unordered_map<char, int> countT;
6
7        if (s.length() != t.length()) return false;
8
9        for(int i = 0; i < s.length(); i++){
10            countS[s[i]]++;
11            countT[t[i]]++;
12        }
13        
14        return countS == countT;
15    }
16};