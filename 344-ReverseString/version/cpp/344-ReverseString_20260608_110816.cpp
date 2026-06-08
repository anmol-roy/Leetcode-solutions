// Last updated: 08/06/2026, 11:08:16
1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int i = 0;
5        int j = s.size()-1;
6        while(i < j){
7            swap(s[i],s[j]);
8            i++;
9            j--;
10        }
11    }
12};