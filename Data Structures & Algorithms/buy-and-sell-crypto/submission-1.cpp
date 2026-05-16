class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentMin = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++ ) {
            currentMin = min(currentMin,prices[i]);
            res = max(res,prices[i] - currentMin);
        }
        return res;
    }
};
