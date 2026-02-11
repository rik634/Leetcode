## Problem statement
- You are given a 0-indexed array nums of length n representing your maximum jump capability from each index.
- You start at index 0. Each element nums[i] represents the maximum number of steps you can jump forward from index i
- Your goal is to reach the last index of the array (nums[n - 1]) using the minimum number of jumps
- Return the minimum number of jumps required to reach the last index.
- You can assume that it is always possible to reach the last index.

### Logic:


### Recursion (brute force)
```cpp
class Solution {
public:
    // Function to find the minimum number of jumps using brute-force recursion
    int jump(vector<int>& nums) {
        return minJumps(nums, 0);
    }

private:
    // Recursive function to explore all possible jump paths
    int minJumps(vector<int>& nums, int position) {
        // If we are already at or beyond the last index, no more jumps needed
        if (position >= nums.size() - 1) return 0;

        // If we can't move from current position
        if (nums[position] == 0) return INT_MAX;

        int minStep = INT_MAX;

        // Try every possible jump from 1 to nums[position]
        for (int jump = 1; jump <= nums[position]; ++jump) {
            int subResult = minJumps(nums, position + jump);

            // If the result is not INT_MAX, update minimum step
            if (subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return minStep;
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(N)

### DP
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((j + nums[j]) >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)

### Optimal
#### Logic:
- We need to reach the last index with the minimum number of jumps. Instead of trying all possible paths (as in brute force), we use a greedy approach. At every step, we try to go as far as we can within the current jump range.We treat each jump as moving through levels in a graph, updating the range of indices we can reach in the next jump.
  1. Start from the first index in the array.
  2. Keep track of the furthest index you can reach so far in the current jump range.
  3. Iterate through each index up to the second-last element.
  4. For every index, update the maximum reachable index from this point.
  5. When you reach the end of the current jump range:
     - Increase your jump count.
     - Update the jump range to the furthest point you could reach so far.
  6. Continue until the loop completes.
  7. Return the total number of jumps needed to reach the last index

##### Solution
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        // Traverse through the array (excluding the last element)
        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            // When we reach the end of the current jump range
            if (i == currentEnd) {
                jumps++;
                // Move the current end to the farthest index we can reach
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
