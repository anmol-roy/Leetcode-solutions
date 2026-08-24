// Last updated: 24/08/2026, 19:57:42
class Solution {
public:
    bool checkDivisibility(int n) {
        int sumDigit = 0;
        int productDigit = 1;
        int num = n;

        while (num > 0) {
            sumDigit += num % 10;
            productDigit *= num % 10;
            num /= 10;
        }

        return n % (sumDigit + productDigit) == 0;
    }
};