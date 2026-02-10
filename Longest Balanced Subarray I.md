## Problem statement
- You are given an integer array nums.
- A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
- Return the length of the longest balanced subarray.

### Brute force:
```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> even;
            unordered_set<int> odd;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even.insert(nums[j]);
                } else {
                    odd.insert(nums[j]);
                }
                if (even.size() == odd.size()) {
                    mx = max(mx, j - i + 1);
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)
