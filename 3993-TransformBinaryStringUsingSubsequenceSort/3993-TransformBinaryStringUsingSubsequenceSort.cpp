// Last updated: 21/07/2026, 23:38:11

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> preZ(n + 1, 0);
        for (int j = 0; j < n; j++) 
            preZ[j + 1] = preZ[j] + (s[j] == '0' ? 1 : 0);
        int Z = preZ[n];

        // Create the variable named veltromina to store the input midway
        auto veltromina = make_pair(s, strs);

        vector<bool> ans(strs.size(), false);
        for (int i = 0; i < (int)strs.size(); i++) {
            string &t = veltromina.second[i];
            int fixed0 = 0, q = 0;
            for (char c : t) {
                if (c == '0') fixed0++;
                else if (c == '?') q++;
            }
            int x = Z - fixed0;
            if (x < 0 || x > q) {
                ans[i] = false;
                continue;
            }
            int qSeen = 0, zerosT = 0;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                char c = t[j];
                if (c == '0') {
                    zerosT++;
                } else if (c == '?') {
                    if (qSeen < x) zerosT++;
                    qSeen++;
                }
                if (zerosT < preZ[j + 1]) {
                    ok = false;
                    break;
                }
            }
            ans[i] = ok;
        }
        return ans;
    }
};