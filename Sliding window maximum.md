## Problem statement
- You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
- Return the max sliding window.



### Solution:
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> mxDeque;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!mxDeque.empty() && mxDeque.front() == (i - k)) {
                mxDeque.pop_front();
            }
            while (!mxDeque.empty() && nums[mxDeque.back()] <= nums[i]) {
                mxDeque.pop_back();
            }
            mxDeque.push_back(i);

            if (i >= (k - 1)) {
                res.push_back(nums[mxDeque.front()]);
            }
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space compelxity: O(n)
