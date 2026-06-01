// Last updated: 01/06/2026, 19:01:47
1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        sort(cost.begin(),cost.end());
5        int total = 0;
6
7        for(int i = cost.size()-1; i >= 0; i -= 3){
8            total += cost[i];
9            if(i-1 >= 0){
10                total += cost[i-1];
11            }
12        }
13        return total;
14    }
15};