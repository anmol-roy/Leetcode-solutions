// Last updated: 12/07/2026, 08:08:54
1class Solution {
2public:
3    int secondsBetweenTimes(string startTime, string endTime) {
4        int start = stoi(startTime.substr(0,2)) * 3600 +
5                    stoi(startTime.substr(3,2)) * 60 + 
6                    stoi(startTime.substr(6,2));
7        int end =   stoi(endTime.substr(0,2)) * 3600 +
8                    stoi(endTime.substr(3,2)) * 60 + 
9                    stoi(endTime.substr(6,2));
10        return end-start;
11    }
12};