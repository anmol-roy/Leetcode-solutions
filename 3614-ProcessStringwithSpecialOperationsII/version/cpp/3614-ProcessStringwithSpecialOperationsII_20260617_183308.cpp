// Last updated: 17/06/2026, 18:33:08
1class Solution {
2public:
3    char processStr(string s, long long k) {
4        int n = s.length();
5
6        long long l = 0;
7        for(char &ch : s) {
8            if(ch == '*'){
9                if( l > 0) {
10                    l--;
11                }
12            } else if(ch == '#'){
13                l*=2;
14            } else if (ch == '%') {
15                continue;
16            } else {
17                l++;
18            }
19        }
20        if( k >= l) {
21            return '.';
22        }
23        for(int i = n-1; i >= 0; i--) {
24            if(s[i] == '*') {
25                l++;
26            } else if (s[i] == '%') {
27                k = l - k - 1;
28            } else if (s[i] == '#') {
29                l = l/2;
30                k = (k >= l) ? k - l : k;
31            } else {
32                l--;
33            }
34
35            if (k == l) {
36                return s[i];
37            }
38        }
39        return '.';
40    }
41};