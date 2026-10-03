// Last updated: 03/10/2026, 23:55:46
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