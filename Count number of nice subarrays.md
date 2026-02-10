## Problem statement


### Brute force
```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0) {
                    c++;
                }
                if (c == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Better
#### Logic:
- Instead of checking every possible subarray, we can speed things up by using prefix sums and a hashmap. We focus on counting how many subarrays have exactly k odd numbers. So, for each index we track how many odd numbers we’ve seen so far. If we’ve seen oddCount odds up to index i, and there was a previous prefix where we had (oddCount-k), then the subarray between those two points has exactly k odd numbers.
- We use a hashmap to store the count of how many times each oddCount has occurred. As we traverse the array, we just lookup how many times we’ve seen (oddCount-k) and add that to the answer.
  1. Use a frequency map to track how often a certain count of odd numbers has occurred in the prefix of the array.
  2. Start by adding a base case to the map: zero odd numbers seen so far has occurred once.
  3. Start traversing the array from left to right:
     - For each element, check if it is odd. If it is, increase the running count of odd numbers seen so far.
     - Check if the frequency map contains the value equal to the current count of odd numbers minus the required count. If yes, it means there are subarrays ending at the current index with exactly the required count of odd numbers. Add the frequency of that value to the final answer.
     - Update the frequency map by increasing the count of the current odd-number total.
  4. Once the entire array is processed, return the accumulated answer as the total number of valid subarrays.
 
#### Solution
```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int l = 0;
        int r = 0;
        int curr = 0;
        while (r < n) {
            if (nums[r] % 2 != 0) {
                curr++;
            }
            if (mp.count(curr - k)) {
                count += mp[curr - k];
            }
            mp[curr]++;
            r++;
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Optimized
#### Logic
- We can't directly count subarrays with exactly K odd numbers using one pass of sliding window. But we can count how many subarrays have at most K odd numbers. If we do this for both K and K-1, then the difference gives us the number of subarrays that have exactly K odd numbers. This works because: countExactlyK = countAtMost(K) - countAtMost(K - 1).
  1. Use a helper function to count the number of subarrays with at most a given number of odd numbers.
  2. Initialize two pointers to define the sliding window.
  3. Expand the window by moving the right pointer.
  4. If the number of odd numbers in the window exceeds the allowed count, move the left pointer to shrink the window.
  5. For each valid window, the number of subarrays ending at the current index is (right - left + 1).
  6. Repeat for K and K - 1, then return their difference.
 
#### Solution
```cpp
class Solution {
public:
    // function to count subarrays with at most k odd numbers
    int countAtMost(vector<int>& nums, int k) {
        // Initialize variables
        int left = 0, res = 0;

        // Traverse through the array
        for (int right = 0; right < nums.size(); right++) {
            // If current number is odd, reduce k
            if (nums[right] % 2 != 0)
                k--;

            // Shrink the window until k is valid
            while (k < 0) {
                if (nums[left] % 2 != 0)
                    k++;
                left++;
            }

            // Add valid subarrays ending at right
            res += (right - left + 1);
        }

        // Return the count of valid subarrays
        return res;
    }

    // Main function to get number of subarrays with exactly k odd numbers
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
