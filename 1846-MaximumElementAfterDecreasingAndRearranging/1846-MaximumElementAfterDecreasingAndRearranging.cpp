// Last updated: 03/10/2026, 23:52:40
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {

            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};