class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int>currentComb;
        helper(nums,0,target,currentComb,result);
        return result;

    }
    void helper(const vector<int>&nums,int idx,int target,
    vector<int> &currentComb,vector<vector<int>> &result){
        if(target == 0){
            result.push_back(currentComb);
            return;
        }
        for(int i = idx; i< nums.size();i++){
            int num = nums[i];
            if(num > target)
                break;
            currentComb.push_back(num);
            helper(nums,i,target-num,currentComb,result);
            currentComb.pop_back();
        }
    }
};
