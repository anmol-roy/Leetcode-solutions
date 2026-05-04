// Last updated: 04/05/2026, 15:42:47
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