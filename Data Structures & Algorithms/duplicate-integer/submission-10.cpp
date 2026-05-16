class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for(const int num: nums){
            if(numSet.count(num)){
                return true;
            }
            numSet.insert(num);
        }
        return false;
    }
};