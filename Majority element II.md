## Problem statement
- Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

### Brute force:
```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        int f = floor(n / 3);

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector<int> res;
        for (auto it : mp) {
            if (it.second > f) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

