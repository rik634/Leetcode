## Problem statement
- You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].
  - base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].
- Return true if the given array is good, otherwise return false.
- Note: A permutation of integers represents an arrangement of these numbers.

### Solution
```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();
        int mx = n - 1;
        unordered_map<int, int> mp;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx || (nums[i] != mx && mp[nums[i]] >= 1)) {
                return false;
            }
            mp[nums[i]]++;
        }
        if (mp.find(mx) == mp.end() ||
            (mp.find(mx) != mp.end() && mp[mx] != 2)) {
            return false;
        }
        return true;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
