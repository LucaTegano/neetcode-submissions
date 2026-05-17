class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;

        // Fissiamo la barra di sinistra
        for (int i = 0; i < n; ++i) {
            int min_height = INT_MAX;
            for(int j = i; j < n; j++){
                min_height = min(min_height,heights[j]);
                int width =  j - i +1;
                int current_area = min_height * width;
                max_area = max(max_area,current_area);
            }
        }
        return max_area;
    }
};
