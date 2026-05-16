class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(const int num : nums ){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num); // Add the number to the set
        }
        return false;
    }
};