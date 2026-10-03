// Last updated: 03/10/2026, 23:53:59
class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        int x = clamp(cx, x1, x2) - cx;
        int y = clamp(cy, y1, y2) - cy;

        return x * x + y * y <= r * r;
    }
};