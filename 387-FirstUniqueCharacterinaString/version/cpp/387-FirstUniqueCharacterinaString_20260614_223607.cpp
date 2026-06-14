// Last updated: 14/06/2026, 22:36:07
1class Solution {
2public:
3    int firstUniqChar(string s) {
4        int n = s.size();
5        unordered_map<char,int> f;
6        for(auto it: s){
7            f[it]++;
8        }
9        for(int i = 0; i < n; i++){
10            if(f[s[i]] == 1){
11                return i;
12            }
13        }
14        return -1;
15    }
16};