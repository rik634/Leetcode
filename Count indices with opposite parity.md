## Problem statement
- You are given an integer array nums of length n.
- The score of an index i is defined as the number of indices j such that:
  - i < j < n, and
  - nums[i] and nums[j] have different parity (one is even and the other is odd).
- Return an integer array answer of length n, where answer[i] is the score of index i.

### Solution
``cpp
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]&1)!=(nums[j]&1))
                {
                    res[i]++;
                }
            }
        }
        return res;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)
