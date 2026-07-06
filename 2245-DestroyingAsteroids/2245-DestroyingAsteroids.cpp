// Last updated: 06/07/2026, 09:52:58
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long sum = mass;
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i]>sum) return false;
            sum += asteroids[i];
        }
        return true;
    }
};