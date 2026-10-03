// Last updated: 03/10/2026, 23:55:10

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st; // Re-added the missing stack declaration
        int depth_counter = 0;
        for(int ch = 0; ch < s.size(); ch++){
            // if(depth_counter == 0){
            //     depth_counter++;
            //     continue;
            // } else {
            //     if(s[ch] == '(' ) {
            //         st.push(s[ch]);
            //         depth_counter++;
            //     } else if (s[ch] == ')' ) {
            //         st.push(s[ch]);
            //         depth_counter--;
            //     }
            // }
            if (s[ch] == '(') {
                if (depth_counter > 0) {
                    st.push(s[ch]);
                }
                depth_counter++;
            } else if (s[ch] == ')') {
                depth_counter--;
                if (depth_counter > 0) {
                    st.push(s[ch]);
                }
            }
        }
            
        


        string r;
        while(!st.empty()){
            r+= st.top();
            st.pop();
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
