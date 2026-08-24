// Last updated: 24/08/2026, 19:58:01
class Solution {
private:
    // Checks if t has prime factors other than 2, 3, 5, or 7
    bool isInvalid(long long t) {
        for (int i = 2; i <= 9; i++) {
            while (t % i == 0) {
                t /= i;
            }
        }
        return t > 1;
    }

    // Counts the minimum single-digit factors needed to clear t
    int minDigitsNeeded(long long t) {
        if (t <= 1) return 0;
        int count = 0;
        long long temp = t;
        for (int d = 9; d >= 2; d--) {
            while (temp % d == 0) {
                count++;
                temp /= d;
            }
        }
        return (temp == 1) ? count : 1e9; // 1e9 handles edge cases where t cannot be formed
    }

    // Generates the smallest digit combination for a given t
    string getSmallestSuffix(long long t, int availableLen) {
        string sol = "";
        for (int d = 9; d >= 2; d--) {
            while (t % d == 0) {
                sol.push_back(d + '0');
                t /= d;
            }
        }
        while ((int)sol.size() < availableLen) {
            sol.push_back('1');
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }

    // Correctly updates t when a digit 'd' is placed
    long long reduceT(long long t, int d) {
        if (d == 0) return t; // Avoid division by zero
        long long g = std::gcd(t, (long long)d);
        return t / g;
    }

public:
    string smallestNumber(string num, long long t) {
        if (isInvalid(t)) return "-1";
        
        int n = num.size();
        
        // Find the first '0' if it exists
        int zeroIdx = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                zeroIdx = i;
                break;
            }
        }

        // Track state of t after matching prefixes
        vector<long long> prefixT(n + 1, t);
        for (int i = 0; i < zeroIdx; i++) {
            prefixT[i + 1] = reduceT(prefixT[i], num[i] - '0');
        }

        // Case 1: The original number itself is already valid (and has no zeros)
        if (zeroIdx == n && prefixT[n] == 1) {
            return num;
        }

        // Case 2: Try to branch out at position i to find a larger lexicographical match
        for (int i = zeroIdx == n ? n - 1 : zeroIdx; i >= 0; i--) {
            int remainingLen = n - 1 - i;
            int startDigit = (num[i] - '0') + 1;
            
            for (int d = startDigit; d <= 9; d++) {
                long long remT = reduceT(prefixT[i], d);
                if (minDigitsNeeded(remT) <= remainingLen) {
                    string sol = num.substr(0, i);
                    sol.push_back(d + '0');
                    sol += getSmallestSuffix(remT, remainingLen);
                    return sol;
                }
            }
        }

        // Case 3: No valid number of length n exists; construct the absolute smallest of length n+1
        int reqLen = n + 1;
        return getSmallestSuffix(t, reqLen);
    }
};
