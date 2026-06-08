// Last updated: 08/06/2026, 10:58:13
1class Solution {
2public:
3    void moveZeroes(vector<int>& arr) {
4    int insertPos = 0;
5
6    for(int i = 0; i < arr.size(); i++){
7        if(arr[i] != 0){
8            swap(arr[i],arr[insertPos]);
9            insertPos++;
10        }
11
12    
13    }
14    }
15};