class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> comb;
        vector<vector<int>> res;
        helper(candidates, 0, target, comb, res);
        return res;
    }

   private:
    void helper(const vector<int>& candidates, int idx, int target, vector<int>& comb,
                vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            int num = candidates[i];
            if (num > target) break;
            if (i > idx && num == candidates[i - 1]) continue;

            comb.push_back(num);
            helper(candidates, i + 1, target - num, comb, res);
            comb.pop_back();
        }
    }
};
