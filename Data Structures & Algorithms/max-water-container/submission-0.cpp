class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1; 
        int maxArea = - 1000;     
        while (left < right) {
            int base = right - left;
            int calculatedHeight  = min(heights[left],heights[right]);
            int area = base * calculatedHeight;
            if (maxArea < area) maxArea = area;
            if (calculatedHeight == heights[left]) left++;
            else if (calculatedHeight == heights[right]) right--;
        }
        return maxArea;
    }
};
