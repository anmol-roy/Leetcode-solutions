// Last updated: 18/06/2026, 21:08:18
1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double minuteAngle = minutes * 6;
5        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
6        double diff = abs(hourAngle - minuteAngle);
7        return min(diff, 360 - diff);
8    }
9};