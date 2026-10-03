// Last updated: 03/10/2026, 23:58:29
class Solution {
public:
    int longestValidParentheses(string s) {
        int answer = 0;
        int open = 0, close = 0;

        for (char ch : s) {
            if (ch == '(') ++open;
            else ++close;

            if (open == close) {
                answer = max(answer, 2 * close);
            } else if (close > open) {
                open = close = 0;
            }
        }

        open = close = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '(') ++open;
            else ++close;

            if (open == close) {
                answer = max(answer, 2 * open);
            } else if (open > close) {
                open = close = 0;
            }
        }

        return answer;
    }
};
