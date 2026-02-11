## Problem statement
- Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

### Logic:
- Initialise a variable maxIndex to keep track of the farthest index we can reach from the start
- Iterate through each index of the array and at each interaction check if the current index is greater than the maximum index we can reach so far.
- If the current index is greater than maxIndex, it means the current index is not reachable hence we return false.
- But if current index is reachable we update the maxIndex to be the maximum of the current value of maxIndex and maximum index we can reach from current index ie. i + nums[i].
- If we exit the loop without returning false, it means we have reached the last index, therefore we can return a true.

### Solution
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
             // If current index is beyond the farthest reachable point
            if (i > mx) {
                return false; // We cannot move further
            }
            int x = nums[i];
            mx = max(mx, i + x);
        }
        return true;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
