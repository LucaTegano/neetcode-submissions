class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map = {}
        result = []

        for s in strs:
            sorted_s = tuple(sorted(s))
            if sorted_s not in anagram_map:
                anagram_map[sorted_s] = []
            anagram_map[sorted_s].append(s)
        
        for value in anagram_map.values():
            result.append(value)
        return result