class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> currentComb;
        vector<vector<int>> result;
        helper(nums,0,target,currentComb,result);
        return result;
    }

private:
    void helper(vector<int> nums,int idx,int target,
        vector<int> & currentComb,vector<vector<int>>& result){
        //base case
        if(target == 0){
            result.push_back(currentComb);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            //prunning
            int num = nums[i];
            if (num > target)
                break;
            currentComb.push_back(num);
            helper(nums,i,target-num,currentComb,result);
            currentComb.pop_back();
        }

       

    }
};
