## Problem statement
- Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
- Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
- The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

### Brute force
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int k = st.size();
        int ind = 0;
        for (auto it : st) {
            nums[ind] = it;
            ind++;
        }
        return k;
    }
};
```
- Time complexity: O(nlogk)
- Space complexity: O(k)

### Better (two pointer)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
```
- Time complexity: O(N)
- Space complexity: O(1)
