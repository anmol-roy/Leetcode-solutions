// Last updated: 06/07/2026, 09:54:22
class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<int , vector<int>, greater <int>>pq;
        int i;
        for(i = 0; i< k; i++){
            pq.push(arr[i]);
        }
        for(i = k; i < n; i++){
            if(arr[i] <= pq.top())
                continue;
            pq.pop();
            pq.push(arr[i]);
        }
        return pq.top();
    }
};