## Problem statement
- You are given an integer array nums of length n.
- An element at index i is called dominant if: nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])
- Your task is to count the number of indices i that are dominant.
- The average of a set of numbers is the value obtained by adding all the numbers together and dividing the sum by the total number of numbers.
- Note: The rightmost element of any array is not dominant.
- Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

### Solution
```cpp
class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size();
        int sum=0;
        sum=nums[n-1];
        int ind=1;
        int count=0;
        for(int i=n-2;i>=0;i--){

            int avg = ((double)sum/ind);
            if(nums[i]>avg)
            {
                count++;
            }
            sum+=nums[i];
            ind++;
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
