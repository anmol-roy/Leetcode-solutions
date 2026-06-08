// Last updated: 08/06/2026, 09:05:28
1class Solution {
2public:
3    int removeDuplicates(vector<int>& arr) {
4       if (arr.empty()) return {};
5        
6        int i = 0, j = 1;
7        while(j < arr.size()){
8            if(arr[i] != arr[j]){
9                i++;
10                arr[i] = arr[j];
11            }
12            j++;
13        }
14        
15       
16        
17        return i + 1;
18    }
19};