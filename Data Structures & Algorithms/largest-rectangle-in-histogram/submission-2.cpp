class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int max_area = 0;

        // Scorre fino a n compreso per svuotare lo stack alla fine usando una barra "fittizia" alta 0
        for (int i = 0; i <= n; ++i) {
            int current_height = (i == n) ? 0 : heights[i];

            // Se la barra corrente è più bassa di quella in cima allo stack, 
            // significa che la barra in cima non può più estendersi a destra.
            while (!s.empty() && current_height < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();

                // Se lo stack è vuoto, la barra poteva estendersi fino all'inizio (indice 0)
                // Altrimenti, il suo confine sinistro è l'elemento che si trova ora in cima allo stack
                int width = s.empty() ? i : i - s.top() - 1;
                
                max_area = max(max_area, height * width);
            }
            s.push(i);
        }

        return max_area;
    }
};