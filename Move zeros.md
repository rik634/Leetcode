## Problem statement
- Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
- Note that you must do this in-place without making a copy of the array

### logic:
- Here, we have array, and we need to manipulate the position of elments in array in-place, 2 pointers is suitable here.
  
### Solution:
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
        
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
