// Last updated: 16/06/2026, 08:55:45
1class Solution {
2public:
3    string processStr(string s) {
4        string res;
5       for(int i = 0; i < s.size(); i++) {
6            if(s[i] == '#'){
7                string temp = res; 
8                res.append(temp);
9            } else if (s[i] == '%' ) {
10                reverse(res.begin(), res.end());
11            } else if (s[i] == '*'){
12                if (!res.empty()) {
13                    res.pop_back();
14                }
15            } else {
16                res += s[i];
17            }
18       }
19       return res;
20    }
21};