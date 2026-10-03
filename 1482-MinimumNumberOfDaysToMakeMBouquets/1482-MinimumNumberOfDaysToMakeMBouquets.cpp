// Last updated: 03/10/2026, 23:53:39
class Solution {
bool calDay(vector<int>& bloomDay, int mid, int m, int k) {
    int flowers = 0;
    int bouquets = 0;
    for(int bloom : bloomDay) {
        if (bloom <= mid) {
            flowers++;

            if(flowers == k) {
                bouquets++;
                flowers = 0;
            } 
        } else {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) {
            return -1;
        }
        int low  = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end()); 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ( calDay(bloomDay, mid, m , k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};