## Problem statement
- Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

### Brute force
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> res(n,0);
       for(int i=0;i<n;i++)
       {
        res[(i+k)%n]=nums[i];
       }
       nums=res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Optimal
```cpp
class Solution {
public:
    void reverseA(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        reverseA(nums, 0, n - 1);
        reverseA(nums, 0, k - 1);
        reverseA(nums, k, n - 1);
    }
};
```
- Time complexity: O(N)
- Space complexity: O(1)
