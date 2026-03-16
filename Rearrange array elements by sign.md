## problem statement
- You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
- You should return the array of nums such that the array follows the given conditions:
  1. Every consecutive pair of integers have opposite signs.
  2. For all integers with the same sign, the order in which they were present in nums is preserved.
  3. The rearranged array begins with a positive integer.
- Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

### Brute force
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Even index should be positive, odd index should be negative
            bool needsPositive = (i % 2 == 0);
            
            if ((needsPositive && nums[i] < 0) || (!needsPositive && nums[i] > 0)) {
                // Find the next correct element
                int j = i + 1;
                while (j < n && ((needsPositive && nums[j] < 0) || (!needsPositive && nums[j] > 0))) {
                    j++;
                }
                
                if (j < n) {
                    // Pull nums[j] to position i by shifting everything in between
                    int temp = nums[j];
                    for (int k = j; k > i; k--) {
                        nums[k] = nums[k - 1];
                    }
                    nums[i] = temp;
                }
            }
        }
        return nums;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Optimal
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr(n,0);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                arr[pos]=nums[i];
                pos+=2;
            }
            else
            {
                arr[neg]=nums[i];
                neg+=2;
            }
        }
        return arr;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
