#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for (std::string str : strs) {
            std:: string sortedString = str;
            std:: sort(sortedString.begin(),sortedString.end());
            anagrams[sortedString].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        for (const auto& pair  : anagrams) {
            result.push_back(pair.second);
        }
        return result;
    }
};
