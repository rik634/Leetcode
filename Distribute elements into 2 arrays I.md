## Problem statement
- You are given a 1-indexed array of distinct integers nums of length n.
- You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:
  - If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
  - The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].
- Return the array result.

### Solution
```cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();
        stack<int> s1;
        stack<int> s2;
        s1.push(nums[0]);
        s2.push(nums[1]);
        for (int i = 2; i < n; i++) {
            if (s1.top() > s2.top()) {
                s1.push(nums[i]);
            } else {
                s2.push(nums[i]);
            }
        }
        int a = s1.size();
        int b = s2.size();
        vector<int> result(n, 0);
        int ind = a - 1;
        while (!s1.empty()) {
            result[ind] = s1.top();
            s1.pop();
            ind--;
        }
        ind = n - 1;
        while (!s2.empty()) {
            result[ind] = s2.top();
            s2.pop();
            ind--;
        }
        return result;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Single array with 2 pointers
```cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[0] = nums[0];
        arr[n - 1] = nums[1];
        int idx = 0, revIdx = n - 1;
        for (int i = 2; i < n; i++) {
            if (arr[idx] > arr[revIdx]) {
                arr[++idx] = nums[i];
            } else {
                arr[--revIdx] = nums[i];
            }
        }
        reverse(arr.begin() + revIdx, arr.end());
        return arr;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
