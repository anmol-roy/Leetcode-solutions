// Last updated: 06/07/2026, 09:52:22
class Solution {
public:
    string processStr(string s) {
        string res;
       for(int i = 0; i < s.size(); i++) {
            if(s[i] == '#'){
                string temp = res; 
                res.append(temp);
            } else if (s[i] == '%' ) {
                reverse(res.begin(), res.end());
            } else if (s[i] == '*'){
                if (!res.empty()) {
                    res.pop_back();
                }
            } else {
                res += s[i];
            }
       }
       return res;
    }
};