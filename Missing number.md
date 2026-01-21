## Problem statement
- Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

### Solution
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                return i;
            }
        }
        return -1;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### better
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int s = (n*(n+1))/2;
        int sum=accumulate(nums.begin(),nums.end(),0);
        return s-sum;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

### Optimized
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int x1 = 0;
        int x2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            x1 = x1 ^ nums[i];
            x2 = x2 ^ i;
        }
        x2 = x2 ^ n;
        return x1 ^ x2;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
