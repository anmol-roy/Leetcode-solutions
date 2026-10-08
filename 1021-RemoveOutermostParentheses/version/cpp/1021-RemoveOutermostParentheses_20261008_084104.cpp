// Last updated: 08/10/2026, 08:41:04
// ,,,
1
2class Solution {
3public:
4    string removeOuterParentheses(string s) {
5        int depth_counter = 0;
6        string r;
7        for(int ch = 0; ch < s.size(); ch++){
8            if(depth_counter == 0){
9                depth_counter++;
10                continue;
11            } else {
12                if(s[ch] == '(' ) {
13                    r += s[ch];
14                    depth_counter++;
15                } else if (s[ch] == ')' ) {
16                    depth_counter--;
17                    if(depth_counter == 0) {continue;}
18                    r += s[ch];
19                }
20            }
21        }
22        return r;
23    }
24};
25