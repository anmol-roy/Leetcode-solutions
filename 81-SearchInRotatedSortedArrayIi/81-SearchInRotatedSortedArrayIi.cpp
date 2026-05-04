// Last updated: 04/05/2026, 15:44:24
class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int l = 0, h = arr.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2; // Better way to prevent overflow
            if (arr[m] == k) return true;

            // Handle duplicate elements that hide the sorted half
            if (arr[l] == arr[m] && arr[m] == arr[h]) {
                l++; // FIXED: Increment left
                h--; // FIXED: Decrement right
                continue; // FIXED: Skip to next iteration
            }

            // Left side is sorted
            if (arr[l] <= arr[m]) {
                if (arr[l] <= k && k < arr[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            } 
            // Right side is sorted
            else {
                if (arr[m] < k && k <= arr[h]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }
        return false; // FIXED: Return bool instead of -1
    }
};
