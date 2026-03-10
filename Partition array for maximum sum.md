## Problem statement
- Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
- Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

### Recursion
```cpp
class Solution {
public:
    void findSum(int ind, int& n, vector<int>& arr, int& k, int curr, int& mx)
    {
        if(ind==n)
        {
            mx=max(mx,curr);
        }

        int currMax=INT_MIN;
        int count=0;
        for(int i=ind;(i)<(ind+k) && i<n;i++)
        {
            count++;
            currMax = max(currMax,arr[i]);
            findSum(i+1,n,arr,k,curr+currMax*count,mx);
        }

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        int mx=INT_MIN;
        findSum(0,n,arr,k,0,mx);
        return mx;
    }
};
```
- Time complexity: O(k^n)
- Space complexity: O(n)

### Memoization
```cpp
class Solution {
public:
    int findSum(int ind, int& n, vector<int>& arr, int& k, int& mx,
                vector<int>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int currMax = INT_MIN;
        int count = 0;
        int ans = 0;
        for (int i = ind; (i) < (ind + k) && i < n; i++) {
            count++;
            currMax = max(currMax, arr[i]);
            ans = max(ans, currMax * count + findSum(i + 1, n, arr, k, mx, dp));
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        int mx = INT_MIN;
        vector<int> dp(n + 1, -1);
        return findSum(0, n, arr, k, mx, dp);
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)


### Tabulation
```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        int mx = INT_MIN;
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int currMax = INT_MIN;
            int count = 0;
            int ans = 0;
            for (int j = i; j < (i + k) && j < n; j++) {
                count++;
                currMax = max(currMax, arr[j]);
                ans = max(ans, currMax * count + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
```
- Time complexity: O(n*k)
- Space complexity: O(n)
