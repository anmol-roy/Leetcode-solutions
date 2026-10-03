// Last updated: 03/10/2026, 23:45:37
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