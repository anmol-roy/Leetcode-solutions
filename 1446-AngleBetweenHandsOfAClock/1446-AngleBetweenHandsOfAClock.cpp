// Last updated: 06/07/2026, 09:53:28
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6;
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double diff = abs(hourAngle - minuteAngle);
        return min(diff, 360 - diff);
    }
};