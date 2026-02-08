## Problem statement
- You are given an integer array nums.
- You must repeatedly apply the following merge operation until no more changes can be made:
- If any two adjacent elements are equal, choose the leftmost such adjacent pair in the current array and replace them with a single element equal to their sum
- After each merge operation, the array size decreases by 1. Repeat the process on the updated array until no more changes can be made.
- Return the final array after all possible merge operations.
- Note: Please do not copy the description during the contest to maintain the integrity of your submissions.

### Solution
```cpp
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        int n = nums.size();
        stack<long long> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(nums[i]);
            } else {
                long long t = nums[i];
                while (!st.empty() && st.top() == t) {
                    st.pop();
                    t = 2 * t;
                }
                st.push(t);
            }
        }
        vector<long long> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)
