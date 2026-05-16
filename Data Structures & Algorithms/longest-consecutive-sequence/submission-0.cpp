class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestSequence = 0;
        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentSequence = 1;
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentSequence += 1;
                }
            longestSequence = std::max(longestSequence, currentSequence);
            }
        }
        return longestSequence;
    }
};
