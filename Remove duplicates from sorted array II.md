## Problem statement
- Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
- Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
- Return k after placing the final result in the first k slots of nums.
- Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

### Brute force
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        map<int, int> mp;
        int n = nums.size();
        for (auto it : nums) {
            mp[it]++;
        }
        int i = 0;
        for (auto it : mp) {
            int num = it.first;
            int freq = it.second;
            int f = min(freq, 2);
            for (int j = 0; j < f; j++) {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### optimized (Two pointer)
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if(n<=2){
            return n;
        }
        int i = 2;
        for (int j = 2; j < n; j++) {
            if (nums[j] != nums[i - 1] || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

