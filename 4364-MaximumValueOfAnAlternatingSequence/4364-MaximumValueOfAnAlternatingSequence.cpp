// Last updated: 19/07/2026, 00:22:34
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long oddPeaks = n / 2;
        long long evenPeaks = (n + 1) / 2;

        long long ans1 = s;
        if(oddPeaks > 0)
            ans1 = s + m + (oddPeaks - 1) * (m - 1);

        long long ans2 = s + (evenPeaks - 1) * (m - 1);

        return max(ans1, ans2);
    }
};