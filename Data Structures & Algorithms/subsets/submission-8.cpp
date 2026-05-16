class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> arr;
        dfs(nums,0,arr,sol);
        return sol;

    }

        void dfs(const vector<int>& nums,int index,
    vector<int>&arr,vector<vector<int>> &sol){
        sol.push_back(arr);
        for(int i = index; i < nums.size();i++){
            arr.push_back(nums[i]);

            dfs(nums,i+1,arr,sol);
            arr.pop_back();
        }
    }
};
