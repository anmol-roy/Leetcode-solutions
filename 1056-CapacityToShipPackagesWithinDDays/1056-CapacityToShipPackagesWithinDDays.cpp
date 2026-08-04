// Last updated: 04/08/2026, 18:32:29
class Solution {
bool canShip(vector<int>& weights, int days, int capacity) {
    int daysUsed = 1;
    int currentLoad = 0;

    for (int weight : weights) {

        if (currentLoad + weight <= capacity) {
            currentLoad += weight;
        }
        else {
            daysUsed++;
            currentLoad = weight;

            if (daysUsed > days)
                return false;
        }
    }

    return true;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high) {
            int mid = low + (high - low ) / 2;
            if (canShip(weights , days , mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};