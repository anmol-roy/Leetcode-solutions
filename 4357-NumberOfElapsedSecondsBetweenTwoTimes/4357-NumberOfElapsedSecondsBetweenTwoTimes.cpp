// Last updated: 19/07/2026, 00:22:39
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start = stoi(startTime.substr(0,2)) * 3600 +
                    stoi(startTime.substr(3,2)) * 60 + 
                    stoi(startTime.substr(6,2));
        int end =   stoi(endTime.substr(0,2)) * 3600 +
                    stoi(endTime.substr(3,2)) * 60 + 
                    stoi(endTime.substr(6,2));
        return end-start;
    }
};