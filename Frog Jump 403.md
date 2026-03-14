## Problem statement
- A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
- Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
- If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

### Brute force
``` cpp
class Solution {
public:
    bool f(int ind, int prevJump, vector<int>& stones,
           unordered_map<int, int>& mp) {
        if (ind == stones.size() - 1) {
            return true;
        }
        bool flag = false;
        // k-1
        if (prevJump > 1 && mp.find(stones[ind] + prevJump - 1) != mp.end()) {
            flag = flag ||
                   f(mp[stones[ind] + prevJump - 1], prevJump - 1, stones, mp);
        }
        // k
        if (mp.find(stones[ind] + prevJump) != mp.end()) {
            flag = flag || f(mp[stones[ind] + prevJump], prevJump, stones, mp);
        }
        // k+1
        if (mp.find(stones[ind] + prevJump + 1) != mp.end()) {
            flag = flag ||
                   f(mp[stones[ind] + prevJump + 1], prevJump + 1, stones, mp);
        }
        return flag;
    }
    bool canCross(vector<int>& stones) {

        int n = stones.size();
        if (stones[1] != 1) {
            return false;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        return f(1, 1, stones, mp);
    }
};
```
- Time complexity: O(3^n)
- Space complexity: O(n) + O(n)

### Memoization
```cpp
class Solution {
public:
    bool f(int ind, int prevJump, vector<int>& stones,
           unordered_map<int, int>& mp, vector<vector<int>>& dp) {
        if (ind == stones.size() - 1) {
            return dp[ind][prevJump] = true;
        }
        if (dp[ind][prevJump] != -1) {
            return dp[ind][prevJump];
        }
        bool flag = false;
        // k-1
        if (prevJump > 1 && mp.find(stones[ind] + prevJump - 1) != mp.end()) {
            flag = flag || f(mp[stones[ind] + prevJump - 1], prevJump - 1,
                             stones, mp, dp);
        }
        // k
        if (mp.find(stones[ind] + prevJump) != mp.end()) {
            flag =
                flag || f(mp[stones[ind] + prevJump], prevJump, stones, mp, dp);
        }
        // k+1
        if (mp.find(stones[ind] + prevJump + 1) != mp.end()) {
            flag = flag || f(mp[stones[ind] + prevJump + 1], prevJump + 1,
                             stones, mp, dp);
        }
        return dp[ind][prevJump] = flag;
    }
    bool canCross(vector<int>& stones) {

        int n = stones.size();
        if (stones[1] != 1) {
            return false;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(1, 1, stones, mp, dp);
    }
};
```
- Time complexity: O(n) (map) + O(n*n)
- Space complexity: O(n) (map) + O(n*n) (dp)

### Tabulation
```cpp
class Solution {
public:
    
    bool canCross(vector<int>& stones) {

        int n = stones.size();
        if (stones[1] != 1) {
            return false;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));

        for(int i=0;i<=n;i++)
        {
            dp[n-1][i]=true;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int prev=0;prev<=i;prev++)
            {
                bool flag = false;
                if(prev>1 && mp.find(stones[i]+prev-1)!=mp.end())
                {
                    flag = flag || dp[mp[stones[i]+prev-1]][prev-1];
                }
                if(mp.find(stones[i]+prev)!=mp.end())
                {
                    flag = flag || dp[mp[stones[i]+prev]][prev];
                }
                if(mp.find(stones[i]+prev+1)!=mp.end())
                {
                    flag = flag || dp[mp[stones[i]+prev+1]][prev+1];
                }
                dp[i][prev]=flag;
            }
        }
        return dp[1][1];
    }
};
```
- Time complexity: O(n) + O(n*n)
- Space complexity: O(n*n)

- You are filling the table from the target (last stone) back to the start. While this is a valid DP approach, it forces you to check mp.find() for every single state. In the Top-Down approach, if a state isn't reachable, the mp.find() for that branch never even executes.

### Optimal
```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {

        int n = stones.size();
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);
        for (int i = 0; i < n; i++) {
            for (auto k : dp[i]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0) {
                        int nextStonePos = stones[i] + jump;
                        auto it = lower_bound(stones.begin() + i + 1,
                                              stones.end(), nextStonePos);
                        if (it != stones.end() && *it == nextStonePos) {
                            int nextInd = it - stones.begin();
                            if (nextInd == n - 1) {
                                return true;
                            }
                            dp[nextInd].insert(jump);
                        }
                    }
                }
            }
        }
        return false;
    }
};
```
- Time complexity:
  The Number of States: O(n*sqrt{n})
  "state" is a unique combination of (current stone, jump size).To get the largest possible jump, the frog must increase its jump size by 1 at every stone ($1, 2, 3, ....,k).
  The total distance covered after k jumps is k*(k+1)/2.Since the max distance is n, we solve k*(k+1)/2 ~=n, which gives a maximum jump size k of O(sqrt{n}).
  With n stones and each having O(sqrt{n}) possible jump sizes, there are O(n *sqrt{n}) reachable states.
  The Work per State: O(log n) For every valid state, the code does:
  Checks: It tries k-1, k, and k+1 (constant time).
  Binary Search: lower_bound is used to find if the next stone exists. Searching in a sorted list of n stones takes O(log n).
  Total Calculation= States * {Work per State} = n*sqrt{n}*log n = O(n*sqrt{n}*log n)}

- Currently, you use lower_bound inside your loops. This adds a logarithmic factor to your time complexity. You can eliminate this by using a Hash Map to pre-store stone positions.

### more optimal
```cpp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        // Optimization 1: Map stone positions to indices for O(1) lookup
        unordered_map<int, int> stoneIdx;
        for (int i = 0; i < n; i++) {
            stoneIdx[stones[i]] = i;
        }

        // Optimization 2: Use the set-based DP to only visit reachable states
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int k : dp[i]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0) {
                        int nextPos = stones[i] + jump;
                        
                        // Check if the next stone exists in O(1)
                        if (stoneIdx.count(nextPos)) {
                            int nextInd = stoneIdx[nextPos];
                            if (nextInd == n - 1) return true; // Early exit
                            dp[nextInd].insert(jump);
                        }
                    }
                }
            }
        }
        return false;
    }
};
```
- Time complexity: O(n*sqrt(n))
- Space complexity: O(n+n*sqrt(n))
