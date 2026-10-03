// Last updated: 03/10/2026, 23:45:01
class Solution {
int minMoves(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2)
        return 0;
    if((r1 + c1) % 2 != (r2 + c2) % 2)
        return -1;
    if (abs(r1 - r2) == abs(c1 - c2))
        return 1;
    return 2;
}
public:
    int minBishopMoves(vector<int>& start, vector<int>& target) {
        int r1 = start[0];
        int r2 = target[0];
        int c1 = start[1];
        int c2 = target[1];
        int ans = minMoves(r1, c1, r2, c2);
        if(ans == -1) return -1;
        else return ans;
    }
};