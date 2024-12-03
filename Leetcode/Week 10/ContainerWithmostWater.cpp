class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maximum = INT_MIN, current_capacity;
        while (i <= j) {
            current_capacity = min(height[i], height[j]) * (j - i);
            maximum = max(maximum, current_capacity);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maximum;
    }
};