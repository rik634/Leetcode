## Problem statemnt
- ou are given an integer array nums and an integer k. Return the number of good subarrays of nums.
- A good subarray is defined as a contiguous subarray of nums that contains exactly k distinct integers. A subarray is a contiguous part of the array.

### Brute force
```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                if (st.size() == k) {
                    count++;
                }
                if (st.size() > k) {
                    break;
                }
            }
        }
        return count;
    }
};
```
 - Time complexity: O(n*n)
 - Space complexity: O(k)

### Better
```cpp
class Solution {
public:
    int findSum(vector<int>& nums, int target) {

        int l = 0;
        int r = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        while (r < n) {
            if (mp.find(nums[r]) == mp.end()) {
                target--;
            }
            mp[nums[r]]++;
            while (target < 0) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                    target++;
                }
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return findSum(nums, k) - findSum(nums, k - 1);
    }
};
```
- Time Complexity:O(N) ,where n is the length of the array. Both calls to atMostK() are linear.
- Space Complexity:O(K) ,where k is the number of distinct elements in the current window. We use a hash map to store frequency counts, which in the worst case could grow to the number of unique elements in the array.
