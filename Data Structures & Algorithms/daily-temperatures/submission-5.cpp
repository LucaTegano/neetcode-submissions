class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempers) {
        int n = tempers.size();
        vector<int> res(n, 0);
        
        // Partiamo dal penultimo giorno e andiamo a ritroso
        for (int i = n - 2; i >= 0; --i) {
            int curr_val = tempers[i];
            int forward_idx = i + 1;
            
            while (forward_idx < n) {
                if (tempers[forward_idx] > curr_val) {
                    res[i] = forward_idx - i;
                    break;
                } else if (res[forward_idx] == 0) {
                    // Se res[forward_idx] è 0, non ci saranno mai giorni più caldi in futuro
                    break;
                }
                
                // Salto i giorni intermedi sfruttando i calcoli già fatti
                forward_idx += res[forward_idx];
            }
        }
        return res;
    }
};