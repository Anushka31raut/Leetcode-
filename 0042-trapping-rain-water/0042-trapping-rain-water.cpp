class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } 
            else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--; 
            }
        }
        return water;
    }
};