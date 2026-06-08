// Last updated: 08/06/2026, 11:04:00
1class Solution {
2public:
3    int removeElement(vector<int>& arr, int val) {
4        
5        int j = 0;
6
7        for(int i = 0; i < arr.size(); i++){
8            if(arr[i] != val){
9                swap(arr[i],arr[j]);
10                j++;
11            }
12        }
13
14        return j;
15    }
16};