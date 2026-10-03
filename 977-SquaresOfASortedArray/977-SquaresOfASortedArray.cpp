// Last updated: 03/10/2026, 23:55:27
class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n); 
    
    int i = 0;
    int j = n - 1;
    int k = n - 1; 

    while (i <= j) {
        if (abs(arr[i]) < abs(arr[j])) {
            result[k] = arr[j] * arr[j];
            j--;
        } else {
            result[k] = arr[i] * arr[i];
            i++;
        }
        k--; 
    }
    return result;

    }
};