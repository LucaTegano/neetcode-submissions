#include <vector>
#include <numeric>   // For std::accumulate
#include <algorithm> // For std::max_element

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // The search space for the speed 'k' is from 1 to the largest pile.
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        int result = right; // Initialize result to a known possible value

        while (left <= right) {
            // To prevent overflow, use (left + (right - left) / 2) instead of (left + right) / 2
            int speed = left + (right - left) / 2;

            // Calculate the total time required to eat all piles with the current 'speed'.
            // Use long long for hours to prevent overflow, as the sum can be large.
            long long hours_needed = 0;
            for (int p : piles) {
                // Calculate hours for one pile: equivalent to ceil(p / speed)
                // (p + speed - 1) / speed is a common integer trick for ceiling division.
                hours_needed += (long long)(p + speed - 1) / speed;
            }

            // Check if this speed is a possible solution
            if (hours_needed <= h) {
                // This speed works. It's a potential answer.
                // Let's try to find an even smaller speed.
                result = speed;
                right = speed - 1;
            } else {
                // This speed is too slow. We must increase the speed.
                left = speed + 1;
            }
        }
        
        return result;
    }
};