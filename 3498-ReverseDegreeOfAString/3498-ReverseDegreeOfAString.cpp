// Last updated: 03/10/2026, 23:48:32
class Solution {
public:
    int reverseDegree(string& s) {
        return accumulate(s.begin(), s.end(), 0, [i=0](int sum, char c) mutable {
            return sum+=(i+++1)*('z'-c+1);
        });
    }
};