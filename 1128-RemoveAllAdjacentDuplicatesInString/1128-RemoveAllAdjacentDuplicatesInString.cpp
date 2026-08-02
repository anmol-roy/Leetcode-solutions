// Last updated: 02/08/2026, 08:59:31
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
