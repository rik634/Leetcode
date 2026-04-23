## Problem statement
- You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. 
- If there is no such j, set arr[i] to be 0.
- Return the array arr.

### Brute force
```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        unordered_map<int, unordered_set<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].insert(i);
        }

        vector<long long> arr(n, 0);
        for (int i = 0; i < n; i++) {

            for (auto it : mp[nums[i]]) {
                arr[i] += abs(i - it);
            }
        }
        return arr;
    }
};
```
- Time complexity: O(n^2)
- Space complexity: O(n)

### Optimized
```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> arr(n, 0LL);
        for (auto it : mp) {

            auto v = it.second;
            long long m = v.size();
            long long sum = accumulate(v.begin(), v.end(), 0LL);
            long long prefix = 0;
            for (int i = 0; i < m; i++) {
                arr[v[i]] = (2 * i - m) * v[i] - 2 * prefix + sum;
                prefix += v[i];
            }
        }
        return arr;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)
