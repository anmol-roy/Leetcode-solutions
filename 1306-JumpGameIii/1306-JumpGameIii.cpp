// Last updated: 03/10/2026, 23:54:25
class Solution {
public:
    int n;

    bool dfs(vector<int>& arr, int i) {
        if (i < 0 || i >= n || arr[i] < 0) {
            return false;
        }

        if (arr[i] == 0) {
            return true;
        }

        int step = arr[i];

        arr[i] *= -1;

        bool left  = dfs(arr, i - step);
        bool right = dfs(arr, i + step);

        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return dfs(arr, start); 
    }
};
