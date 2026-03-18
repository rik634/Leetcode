## Problem statement
- You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
- Return the max sliding window.

### Brute force
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> res;
        for (int i = 0; i <= n - k; i++) {
            int mx = INT_MIN;
            for (int j = i; j < (i + k); j++) {
                mx = max(mx, nums[j]);
            }
            res.push_back(mx);
        }
        return res;
    }
};
```
- Time complexity: O(n*k)
- Space complexity: O(n/k)

### Solution:
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> mxDeque;
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            while (!mxDeque.empty() && nums[mxDeque.back()] < nums[i]) {
                mxDeque.pop_back();
            }
            mxDeque.push_back(i);
        }
        res.push_back(nums[mxDeque.front()]);
        for (int i = k; i < n; i++) {
            int X = nums[i];
            while (!mxDeque.empty() && nums[mxDeque.back()] < X) {
                mxDeque.pop_back();
            }
            mxDeque.push_back(i);
            if (mxDeque.front() == i - k) {
                mxDeque.pop_front();
            }
            res.push_back(nums[mxDeque.front()]);
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space compelxity: O(n)
