// Last updated: 04/05/2026, 15:44:59
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_water = 0;

        while (left < right) {
            
            int h = min(height[left], height[right]);
            
            int w = right - left;
            
            max_water = max(max_water, h * w);

            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
