## problem statement
- We are given a stick of length N and a cuts array of size C. The stick has markings as shown, and the cuts array depicts the marking at which the stick needs to be cut (shown in red).
- We need to find the minimum cost incurred to cut the stick at all the cut points.

### Recursion
```cpp
class Solution {
public:
    // Recursive function to find the minimum cost to cut between indices i and j in cuts
    int findMinimumCost(int i, int j, vector<int> &cuts) {
        // Base case: no cuts to consider
        if (i > j) {
            return 0;
        }

        int mini = INT_MAX;

        // Try cutting at every position between i and j
        for (int ind = i; ind <= j; ind++) {
            // Cost of making the current cut plus
            // cost of cutting left and right sub-segments recursively
            int ans = cuts[j + 1] - cuts[i - 1] +
                      findMinimumCost(i, ind - 1, cuts) +
                      findMinimumCost(ind + 1, j, cuts);

            // Update minimum cost
            mini = min(mini, ans);
        }

        return mini;
    }

    // Function to calculate minimum total cost to cut the stick
    int minimumCost(int n, int c, vector<int> &cuts) {
        // Add the two ends of the stick to the cuts array
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // Sort the cuts array
        sort(cuts.begin(), cuts.end());

        // Compute the minimum cost to make all cuts between indices 1 and c
        return findMinimumCost(1, c, cuts);
    }
};
```
- time complexity: O(2^C) (C=number of cuts)
   - C represents the number of cuts (the size of the cuts vector).The Logic: In each function call, you iterate through all possible cut positions.
   - For each valid cut p, you split the problem into two recursive calls.
- Space complexity: O(C)

### Memoization
```cpp
class Solution {
public:
    int f(int& n, vector<int>& cuts, int i, int j,vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k <= j; k++) {
            int p1 = f(n, cuts, i, k - 1,dp);
            int p2 = f(n, cuts, k + 1, j,dp);
            int curr = cuts[j + 1] - cuts[i - 1];
            mn = min(mn, p1 + p2 + curr);
        }
        return dp[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {

        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return f(n, cuts, 1, c,dp);
    }
};
```
- Time complexity: O(C*C*C)
- Space complexity: O(C*C) + O(C)

### Tabulation
```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = i; j <= c; j++) {
                int mn = INT_MAX;
                for (int k = i; k <= j; k++) {
                    mn = min(mn, dp[i][k - 1] + dp[k + 1][j] + cuts[j + 1] -
                                     cuts[i - 1]);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][c];
    }
};
```
- Time complexity: O(c*c*c)
- Space complexity: O(c*c) + O(clogc)
