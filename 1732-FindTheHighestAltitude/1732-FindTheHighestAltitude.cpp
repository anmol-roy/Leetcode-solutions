// Last updated: 03/10/2026, 23:52:53
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int current_altitude = 0;
        int max_altitude = 0;
        for(int i = 0; i < n ; i++) {
            current_altitude += gain[i];
            max_altitude = max(max_altitude, current_altitude);
        }  
        return max_altitude;
    }
};