## Problem statement
- You are given an integer array nums consisting of n elements, and an integer k.
- Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

### Solution
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int mx = INT_MIN;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        mx = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            mx = max(mx, sum);
        }
        return double(mx) / k;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
