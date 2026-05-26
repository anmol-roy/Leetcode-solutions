// Last updated: 26/05/2026, 19:23:34
1class Solution {
2public:
3    static int numberOfSpecialChars(string& word) {
4        bitset<26> a=0, A=0;
5        for(char c: word){
6            if (c>='a') a[c-'a']=1;
7            else A[c-'A']=1;
8        }
9        a=a&A;
10        return a.count();
11    }
12};