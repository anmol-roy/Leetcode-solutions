// Last updated: 04/05/2026, 15:43:14
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
    int insertPos = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[i],arr[insertPos]);
        insertPos++;
        }
    }
    }
};