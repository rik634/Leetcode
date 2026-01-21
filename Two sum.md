## Problem statement
- Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
- You may assume that each input would have exactly one solution, and you may not use the same element twice.

### Brute force
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[i] + nums[j]) == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### better
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            
            int b = target-nums[i];
            if(mp.find(b)!=mp.end() && i!=mp[b])
            {
                return {i,mp[b]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Binary search
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back({nums[i], i});
        }
        sort(res.begin(), res.end());

        int l = 0;
        int r = n - 1;
        while (l < r) {
            int sum = res[l].first + res[r].first;
            if (sum == target) {
                return {res[l].second, res[r].second};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
```
- Time complexity: O(n) + O(nlogn)= O(nlogn)
- Space complexity: O(n)
