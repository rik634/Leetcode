## problem statement
- Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
  1. answer[i] % answer[j] == 0, or
  2. answer[j] % answer[i] == 0
- If there are multiple solutions, return any of them.


### Brute force
```cpp
class Solution {
public:
    void f(int ind, int& n, vector<int>& nums, vector<int>& curr,
           vector<int>& res) {
        if (ind == n) {
            if (curr.size() > res.size()) {
                res = curr;
            }
            return;
        }
        f(ind + 1, n, nums, curr, res);
        if (curr.size() == 0 ||
            (curr.size() > 0 && nums[ind] % curr[curr.size() - 1] == 0)) {
            curr.push_back(nums[ind]);
            f(ind + 1, n, nums, curr, res);
            curr.pop_back();
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        vector<int> curr;
        f(0, n, nums, curr, res);
        return res;
    }
};
```
- Time complexity: O(nlogn) + O(n* 2^n)
- Space complexity: O(n)

### optimal
```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> parent(n, -1);
        vector<int> dp(n, 1);

        int len = 0;
        int ind = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < (dp[j] + 1)) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > len) {
                len = dp[i];
                ind = i;
            }
        }

        while (parent[ind] != -1) {
            ans.push_back(nums[ind]);
            ind = parent[ind];
        }
        ans.push_back(nums[ind]);

        return ans;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)
