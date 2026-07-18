// Last updated: 19/07/2026, 00:22:47

class Solution {
public:
    int minCost(string s, string t, vector<vector<string>>& r, vector<int>& c) {
    
        int n = s.size(), m = r.size();
        const long long INF = 1e18;
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == t[i]) dp[i] = dp[i + 1];

            for (int j = 0; j < m; j++) {
                string &p = r[j][0], &rep = r[j][1];
                int L = p.size(), star = 0;
                if (i + L > n) continue;

                bool ok = 1;
                for (int k = 0; k < L; k++) {
                    if (rep[k] != t[i + k]) {
                        ok = 0;
                        break;
                    }
                    if (p[k] == '*') star++;
                    else if (p[k] != s[i + k]) {
                        ok = 0;
                        break;
                    }
                }

                if (ok)
                    dp[i] = min(dp[i], dp[i + L] + c[j] + star);
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};