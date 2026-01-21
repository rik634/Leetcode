## problem statement
- Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array..

### Solution
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                c++;
            } else {
                mx = max(mx, c);
                c = 0;
            }
        }
        mx = max(mx, c);
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
