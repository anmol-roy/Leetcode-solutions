// Last updated: 24/08/2026, 20:00:46
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 1 ) return arr[0];
        if (arr.size() == 0 ) return - 1;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            if (arr[mid] < arr[mid+1] ) low = mid + 1;
            else high = mid ;
        }
        return -1;
    }
};