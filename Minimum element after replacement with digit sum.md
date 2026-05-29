## Problem statement
- You are given an integer array nums.
- You replace each element in nums with the sum of its digits.
- Return the minimum element in nums after all replacements.

### Solution
```cpp
class Solution {
public:
    int findDigSum(int num) {
        int c = 0;
        while (num > 0) {
            c += (num % 10);
            num /= 10;
        }
        return c;
    }
    int minElement(vector<int>& nums) {

        int mn = INT_MAX;
        for (auto it : nums) {
            int sum = findDigSum(it);
            mn = min(mn, sum);
        }
        return mn;
    }
};
```
- Time complexity: O(n*d)
- Space complexity: O(1)
