// Last updated: 03/10/2026, 23:55:12
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char> st;
        string c = "";
        
        for (int i = s.length() - 1; i >= 0; i--) {
            char ch = s[i]; 
            
            if (!st.empty() && st.top() == ch) {
               st.pop(); 
            } else {
               st.push(ch);            
            }
        }

        while (!st.empty()) {
            c += st.top();
            st.pop();
        }

        return c;
    }
};
