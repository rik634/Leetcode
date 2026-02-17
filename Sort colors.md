## Problem statement
- Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
- We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
- You must solve this problem without using the library's sort function.

### Brute force
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) { sort(nums.begin(), nums.end()); }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(1)

### better
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++) {
            zero += nums[i] == 0 ? 1 : 0;
            one += nums[i] == 1 ? 1 : 0;
            two += nums[i] == 2 ? 1 : 0;
        }
        int ind = 0;
        while (zero > 0) {
            nums[ind] = 0;
            ind++;
            zero--;
        }
        while(one>0)
        {
            nums[ind]=1;
            ind++;
            one--;
        }
        while(two>0)
        {
            nums[ind]=2;
            ind++;
            two--;
        }
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

### Optimized (dutch national flag algorithm)
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
         
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
    
};
```
- Time complexity: O(n)
- Space complexity: O(1)
