class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(int num : nums){
           counts[num]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets (n+1);
        for(auto& [num,freq]: counts){
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for(int i = n; i >= 0;i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
