class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        // I will implement buckets to order the frequence
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
          for (auto& [num, freq] : counts) {
            bucket[freq].push_back(num);
        }

        vector<int> result;
        for(int i = n; i >= 0; i--){
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
