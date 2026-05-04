// Last updated: 04/05/2026, 15:43:37
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // Edge case: no primes less than 2

        vector<bool> isPrime(n, true); // Initialize all entries as true
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
                // Avoid overflow by checking if i * i is still less than n
                if ((long long)i * i < n) {
                    // Mark all multiples of i as non-prime
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        return count;
    }
};