## Problem statement
- Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

### Brute force
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int mn = INT_MAX;
            for (int j = i; j < n; j++) {
                mn = min(mn, heights[j]);
                mx = max(mx, mn * (j - i + 1));
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Optimal
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int mx = 0;
        stack<int> st;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            mx = max(mx, heights[i] * (right[i] - left[i] + 1));
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(3*N)

### One pass (optimal)
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        int mx = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int w;
                if (st.empty()) {
                    w = i;
                } else {
                    w = i - st.top() - 1;
                }
                mx = max(mx, w * h);
            }
            st.push(i);
        }
        return mx;
    }
};
```
- Time Complexity: O(N) + O(N). For loop used along with a while loop
- Space Complexity: O(N). Used for stack
