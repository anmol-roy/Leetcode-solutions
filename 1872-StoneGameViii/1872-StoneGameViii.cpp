// Last updated: 03/10/2026, 23:52:19
class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
        int n = A.size();
        for (int i = 1; i < n; i++)
            A[i] += A[i - 1];

        int ans = A.back();
        for (int i = n - 2; i > 0; i--)
            ans = max(ans, A[i] - ans);

        return ans;
    }
};