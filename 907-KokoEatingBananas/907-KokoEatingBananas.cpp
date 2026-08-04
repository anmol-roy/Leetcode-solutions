// Last updated: 04/08/2026, 18:32:42
class Solution {
bool can(vector<int>& piles, int speed, int h)
{
    long long hours = 0;

    for(int pile : piles)
    {
        hours += (pile + speed - 1) / speed;

        if(hours > h)
            return false;
    }

    return true;
}


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low  = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid =  low + (high - low) / 2;     
            if (can(piles, mid, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;

    }
};