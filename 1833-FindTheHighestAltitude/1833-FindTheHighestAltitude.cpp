// Last updated: 06/07/2026, 09:53:18
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_alt = 0;
        int max_alt = 0;

        for (int g : gain){
            current_alt += g;
            max_alt = max(max_alt, current_alt);
        }
        return max_alt;
    }
};