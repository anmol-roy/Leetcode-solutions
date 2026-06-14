// Last updated: 14/06/2026, 23:02:52
1class Solution {
2    bool fun(unordered_map<char, int>& have, unordered_map<char, int>& need) {
3        for (auto it : need) {
4            char ch = it.first;
5            int countNeeded = it.second;
6            
7            if (have[ch] < countNeeded) {
8                return false;
9            }
10        }
11        return true;
12    }
13
14public:
15    bool canConstruct(string ransomNote, string magazine) {
16        unordered_map<char, int> need; 
17        unordered_map<char, int> have; 
18
19        for (auto it : ransomNote) {
20            need[it]++;
21        }
22        for (auto it : magazine) {
23            have[it]++;
24        }
25        
26        return fun(have, need);
27    }
28};
29