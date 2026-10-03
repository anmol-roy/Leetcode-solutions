// Last updated: 03/10/2026, 23:52:37
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum+=costs[i];
            if(sum > coins){
                return i;
            }
        }
        return n;
    }
};