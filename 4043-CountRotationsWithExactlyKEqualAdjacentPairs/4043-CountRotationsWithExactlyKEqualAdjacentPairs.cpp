// Last updated: 03/10/2026, 23:45:03
class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int result = 0;
        for (int rotation = 0; rotation < n; rotation++) {
            int score = 0;
            for (int i = 0; i < n - 1; i++) {
                int origI = (i + rotation) % n;
                int origNext = (i + 1 + rotation) % n;
                if (s[origI] == s[origNext]) score ++;
            }
            if (score == k) result++;
        }
        return result;
    }
};