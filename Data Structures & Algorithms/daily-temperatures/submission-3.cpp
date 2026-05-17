class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempers) {
        int n = tempers.size();
        vector<int> res(n,0);
        stack<int> s;
        for(int i = 0;i < n; ++i){
            while(!s.empty() && tempers[i] > tempers[s.top()]){
                int stackIdx = s.top();
                s.pop();
                res[stackIdx] = i - stackIdx;
            }

            s.push(i);

        }
        return res;
    }
};
