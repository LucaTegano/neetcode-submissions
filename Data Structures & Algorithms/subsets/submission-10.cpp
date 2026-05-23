class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsetCount = 1 << n; // 2^n
        vector<std::vector<int>> result;

        for (int i = 0; i < subsetCount; ++i) {
            vector<int> current;
            for (int j = 0; j < n; ++j) {
                // Check if the j-th bit of i is set
                if ((i >> j) & 1) {
                    current.push_back(nums[j]);
                }
            }
            result.push_back(current);
        }
        return result;
    }
};
