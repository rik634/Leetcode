## Problem statement



### Recursion (brute force)
```cpp
class Solution {
public:
    static bool myComp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int f(int ind, int prev, vector<vector<int>>& envelopes) {
        if (ind == envelopes.size()) {
            return 0;
        }
        // not take
        int notTake = f(ind + 1, prev, envelopes);
        int take = INT_MIN;
        if (prev == -1 || (envelopes[ind][0] > envelopes[prev][0] &&
                 envelopes[ind][1] > envelopes[prev][1])) {
            take = 1 + f(ind + 1, ind, envelopes);
        } 
        return max(notTake, take);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),myComp);
        return f(0, -1, envelopes);
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(n)

### DP
```cpp
class Solution {
public:
    static bool myComp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), myComp);
        vector<int> dp(n, 1);

        int mx = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] &&
                    envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};
```
- Time complexity: O(n*n) + O(nlogn)
- Space complexityL O(n)

### Binary search
```cpp
class Solution {
public:
    static bool myComp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), myComp);
        int len = 0;
        vector<int> lis;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                lis.push_back(envelopes[i][1]);
            } else {
                if (envelopes[i][1] > lis.back()) {
                    lis.push_back(envelopes[i][1]);

                } else {
                    auto c =
                        lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
                    *c = envelopes[i][1];
                }
            }
            len = max(len, (int)lis.size());
        }

        return len;
    }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(n)
