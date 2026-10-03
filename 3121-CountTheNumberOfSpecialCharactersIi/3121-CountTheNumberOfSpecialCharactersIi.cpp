// Last updated: 03/10/2026, 23:49:32
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<27> A[2];

        for (auto& ch : word) {
            int i = ch & 31;
            int Case = (ch >> 5) & 1;

            A[Case].set(i, !(Case & A[0][i]));
        }

        return (A[0] & A[1]).count();
    }
};