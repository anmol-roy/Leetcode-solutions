// Last updated: 06/07/2026, 09:53:43
class Solution {

public:
    int fib(int n) {
        if ( n <= 1) return n;
        return fib(n-1) + fib( n - 2);
    }
};