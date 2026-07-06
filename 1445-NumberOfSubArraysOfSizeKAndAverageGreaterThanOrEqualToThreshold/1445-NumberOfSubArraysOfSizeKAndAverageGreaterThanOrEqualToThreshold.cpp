// Last updated: 06/07/2026, 09:53:30
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        long long avg = 0;
        int sum = 0;
        int count = 0;

        for(int i = 0; i < k ; i++) {
            sum += arr[i];
        }

        avg = sum / k;
        avg >= threshold ? count++ : count = count ;

        for(int i = k; i < n; i++) {
            sum += arr[i] - arr[i-k];
            avg = sum / k;
            avg >= threshold ? count++ : count = count ;
        }
        return count;


    }
};