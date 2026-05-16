class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;

        int curr = nums[0];
        int best = nums[0];

        for(size_t i = 1; i < nums.size(); i++){
            curr = max(nums[i],nums[i] + curr);
            best = max(best,curr);
        }

        return best;
    }
};
