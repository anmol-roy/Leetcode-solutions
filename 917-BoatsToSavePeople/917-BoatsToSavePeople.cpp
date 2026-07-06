// Last updated: 06/07/2026, 09:53:45
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        int n = people.size();

        int left = 0 , right = n - 1;

        sort(people.begin(), people.end());

        while(left <= right){
            if(people[left] + people[right] <= limit){
                left++;
            } 
            right--;
            boats++;
        }
        return boats;
    }
};