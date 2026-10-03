// Last updated: 03/10/2026, 23:46:06
class Solution {
public:
    int countCommas(int n) {
        long long answer = 0;
        long long threshold = 1000;

        while (threshold <= n) {
            answer += n - threshold + 1;
            threshold *= 1000;
        }
         return static_cast<int>(answer);
    }
};