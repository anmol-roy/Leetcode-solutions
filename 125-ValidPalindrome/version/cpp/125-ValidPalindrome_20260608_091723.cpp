// Last updated: 08/06/2026, 09:17:23
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int i = 0 , j = s.size();
5        while(i < j) {
6            if(!isalnum(s[i])) {
7                i++;
8            } else if(!isalnum(s[j])){
9                j--;
10            } else {
11                if (tolower(s[i]) != tolower(s[j])) {
12                    return false; 
13                }
14                i++;
15                j--;
16            }
17        }
18        return true;
19        
20    }
21};