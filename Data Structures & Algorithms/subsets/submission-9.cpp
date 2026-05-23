class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      //Brute force solution  
      vector<vector<int>> result;
      vector<int> current;
      backtrack(nums,0,current,result);
      return result;
    }
    void backtrack(const vector<int>&nums,int index,vector<int>&current,
    vector<vector<int>>& result){
        result.push_back(current);
        for(int i = index; i < nums.size();i++){
            current.push_back(nums[i]);
            backtrack(nums,i+1,current,result);
            current.pop_back();
        }
    }
};
