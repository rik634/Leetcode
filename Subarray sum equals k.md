## Problem statement
- Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
- A subarray is a contiguous non-empty sequence of elements within an array.

### Logic:
- hash table + prefix sum

### Brute force
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
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

### Optimized
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        int sum = 0;
        int n = nums.size();
        int count = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int t = sum - k;
            if (mp.find(t) != mp.end()) {
                count += mp[t];
            }
            mp[sum]++;
        }
        return count;
    }
};
```
