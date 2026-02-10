## Problem statement
- Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

### Brute force
```cpp
class Solution {
public:
    // Function to find the longest subarray with at most k zero flips
    int longestOnes(vector<int>& nums, int k) {

        // Variable to store the maximum length of valid subarray
        int maxLen = 0;

        // Loop to pick every possible starting point
        for (int i = 0; i < nums.size(); i++) {

            // Counter for zeros in the current subarray
            int zeros = 0;

            // Loop to pick every possible ending point
            for (int j = i; j < nums.size(); j++) {

                // If current element is zero, increment zero count
                if (nums[j] == 0) {
                    zeros++;
                }

                // If number of zeros exceeds k, break this subarray
                if (zeros > k) {
                    break;
                }

                // Update max length if this subarray is valid
                maxLen = max(maxLen, j - i + 1);
            }
        }

        // Return the length of the longest valid subarray
        return maxLen;
    }
};

```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Better
```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0;
        int r = 0;
        int zero = 0;
        int mx = 0;
        while (r < n) {
            if (nums[r] == 0) {
                zero++;
            }
            while (zero > k) {
                if (nums[l] == 0) {
                    zero--;
                }
                l++;
            }
            mx = max(mx, r - l + 1);
            r++;
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

### Optimized

#### Logic:
- We can optimize the standard sliding window approach by eliminating the inner while-loop. Instead of using an explicit loop to shrink the window when the number of zeros exceeds the allowed flips (K),
- we can use a single conditional check to move the left pointer forward only when needed. This ensures that each pointer moves in a controlled and efficient manner without unnecessary loop nesting.
- The logic remains similar to the standard sliding window, but this structure can make the code slightly faster and cleaner in certain languages.

#### Solution
```cpp
class Solution {
public:
    // Function to find the longest subarray with at most k zero flips
    int longestOnes(vector<int>& nums, int k) {

        // Left pointer of the sliding window
        int left = 0;

        // Counter for zeros in the current window
        int zerocount = 0;

        // Variable to store the maximum valid window length
        int maxlen = 0;

        // Right pointer expands the window
        for (int right = 0; right < nums.size(); right++) {

            // If current element is 0, increment zerocount
            if (nums[right] == 0) {
                zerocount++;
            }

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zerocount > k) {
                if (nums[left] == 0) {
                    zerocount--;
                }
                // Shrink the window from left
                left++; 
            }

            // Update the maximum window size
            maxlen = max(maxlen, right - left + 1);
        }

        // Return the maximum length found
        return maxlen;
    }
};
```
- Time compelxity: O(n)
- Space complexity: O(1)
