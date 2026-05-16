class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequency_map = {}
        result = []
        for num in nums:
            frequency_map[num] = frequency_map.get(num, 0) + 1
        sorted_items = sorted(frequency_map.items(), key=lambda item: item[1], reverse=True)

        for i in range(k):
            result.append(sorted_items[i][0])
        return result