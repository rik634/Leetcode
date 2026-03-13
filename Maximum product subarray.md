## Problem statement
- Given an integer array nums, find a subarray that has the largest product, and return the product.
- The test cases are generated so that the answer will fit in a 32-bit integer.
- Note that the product of an array with a single element is the value of that element.

### Brute force
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            int num = 1;
            for (int j = i; j < n; j++) {
                num = num * nums[j];
                mx = max(mx, num);
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Better
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int pre = 1;
        int suff = 1;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (pre == 0) {
                pre = 1;
            }
            if (suff == 0) {
                suff = 1;
            }
            pre *= nums[i];
            suff *= nums[n - i - 1];
            mx = max(mx, max(pre, suff));
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

### Optimal
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int ans = nums[0];
        int mx = nums[0];
        int mn = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (curr < 0) {
                swap(mx, mn);
            }
            mx = max(curr, mx * curr);
            mn = min(curr, mn * curr);
            ans = max(ans, mx);
        }
        return ans;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
