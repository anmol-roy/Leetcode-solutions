// Last updated: 03/10/2026, 23:55:33
class Solution {

public:
    int fib(int n) {
        if ( n <= 1) return n;
        return fib(n-1) + fib( n - 2);
    }
};