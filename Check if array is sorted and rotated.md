## Problem statement
- Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
- There may be duplicates in the original array.
- Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

### Brute force
- we will rotate n-1 times, and check everytime if the array is sorted.
```cpp
class Solution {
public:
    bool checkIfSorted(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }
        return count == 0;
    }
    bool check(vector<int>& nums) {

        int n = nums.size();
        if (checkIfSorted(nums)) {
            return true;
        }
        for (int i = 0; i < n - 1; i++) // rotating n times
        {
            int temp = nums[0];
            for (int j = 0; j < n - 1; j++) {
                nums[j] = nums[j + 1];
            }
            nums[n - 1] = temp;
            if (checkIfSorted(nums)) {
                return true;
            }
        }
        return false;
    }
};
```
- Time complexity: O(n) + O(n*(n+n)) = O(n*n)
- Space complexity: O(1)

### different brute force
- here, we are creating a sorted array, and comparing each rotation with this sorted array
```cpp
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            bool isMatch = true;
            for (int j = 0; j < n; j++) {
                if (nums[(i + j) % n] != arr[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }
        return false;
    }
};
```
- Time complexity: O(n) + O(nlogn) + O(n*n)
- Space complexity: O(n)

### better
- we will traverse through the array. If the array is sorted or sorted and rotated, there will be either one peak or no peak
```cpp
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        if (n == 0 || n == 1) {
            return true;
        }
        int count = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
            }
        }
        if (nums[0] < nums[n - 1]) {
            count++;
        }
        return count == 1 || count == 0;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)


  
