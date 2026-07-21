// Last updated: 21/07/2026, 23:38:25
class Solution {
public:
    int booth(const string &s) {
        int n = s.size();
        if (n == 0) return 0;

        string t = s + s;
        int i = 0, j = 1, k = 0;

        while (i < n && j < n) {
            while (k < n && t[i + k] == t[j + k]) k++;

            if (k == n) break;

            if (t[i + k] > t[j + k]) {
                i = i + k + 1;
                if (i <= j) i = j + 1;
            } else {
                j = j + k + 1;
                if (j <= i) j = i + 1;
            }
            k = 0;
        }

        return min(i, j);
    }

    string canonical(string s) {
        if (s.empty()) return "";

        int st = booth(s);
        return s.substr(st) + s.substr(0, st);
    }

    int minimumGroups(vector<string>& words) {
        auto brenolcavi = words;

        unordered_set<string> st;

        for (auto &w : brenolcavi) {
            string even, odd;

            for (int i = 0; i < (int)w.size(); i++) {
                if (i & 1)
                    odd += w[i];
                else
                    even += w[i];
            }

            string key = canonical(even) + "#" + canonical(odd);
            st.insert(key);
        }

        return st.size();
    }
};