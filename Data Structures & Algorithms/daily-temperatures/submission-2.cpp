class Solution {
   public:
    // return int -> number of days after the ith || 0
    // input .size  = output.size()
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prevIndex = s.top();
                s.pop();
                res[prevIndex] = i - prevIndex;
            }

            s.push(i);
        }
        return res;
    }
};
//[20,24,21,19,14,10,42,91]