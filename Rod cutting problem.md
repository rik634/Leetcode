## Problem statement:
- Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing).
- Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

### Logic:
- The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an item that will in the long term give less value.
- As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which gives us the maximum value in the given constraints.

### Recursion:
```cpp
class Solution {
public:
    int f(int ind, int N, vector<int>& price) {
        // Base Case: If we are at the first piece (length 1)
        if (ind == 0) {
            // We can take N pieces of length 1
            return N * price[0];
        }

        // Option 1: Do not take the current piece
        int notTake = f(ind - 1, N, price);

        // Option 2: Take the current piece (if it fits)
        int take = INT_MIN;
        int rodLength = ind + 1;
        if (rodLength <= N) {
            // Stay at same index 'ind' because we can reuse the same length
            take = price[ind] + f(ind, N - rodLength, price);
        }

        return max(take, notTake);
    }

    int rodCutting(vector<int>& price, int n) {
        // Start recursion from the last possible piece length (n)
        return f(n - 1, n, price);
    }
};
```
- Time complexity: O(2^N) (N=length of rod)
-  Space complexityL O(N (recursive stack space)

### Memoization
```cpp
class Solution {
public:
    int f(int ind, int N, vector<int>& price,vector<vector<int>>& dp) {
        // Base Case: If we are at the first piece (length 1)
        if (ind == 0) {
            // We can take N pieces of length 1
            return N * price[0];
        }
        if(dp[ind][N]!=-1){
           return dp[ind][N];
        }
        // Option 1: Do not take the current piece
        int notTake = f(ind - 1, N, price,dp);

        // Option 2: Take the current piece (if it fits)
        int take = INT_MIN;
        int rodLength = ind + 1;
        if (rodLength <= N) {
            // Stay at same index 'ind' because we can reuse the same length
            take = price[ind] + f(ind, N - rodLength, price,dp);
        }

        return dp[ind][N]= max(take, notTake);
    }

    int rodCutting(vector<int>& price, int n) {
        // Start recursion from the last possible piece length (n)
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n - 1, n, price,dp);
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n) + O(n) (recursive stack space)

### Tabulation:
```cpp
class Solution {
  public:
    // Function to compute maximum price obtainable by cutting the rod
    int rodCutting(vector<int> price, int n) {

        // Initialize a DP table where dp[i][j] stores the max price 
        // using first i rod lengths to make total rod length j
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Fill the base case: only using the first rod length (length = 1)
        for(int length = 0; length <= n; length++) {
            // We can use rod of length 1 (index 0) multiple times
            dp[0][length] = length * price[0];
        }

        // Iterate through each rod piece starting from index 1
        for(int i = 1; i < n; i++) {
            for(int length = 0; length <= n; length++) {

                // Option 1: Do not cut with this rod (copy from above)
                int notTake = dp[i - 1][length];

                // Option 2: Cut with current rod length (reuse allowed)
                int take = INT_MIN;
                int rodLength = i + 1;

                // Check if this rod fits in current length
                if(rodLength <= length) {
                    take = price[i] + dp[i][length - rodLength];
                }

                // Store the best value in the DP table
                dp[i][length] = max(take, notTake);
            }
        }

        // Return the answer from the last row and column (full rod length)
        return dp[n - 1][n];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)

### Space optimized
```cpp
class Solution {
public:
    // Function to solve the rod cutting problem
    int rodCutting(vector<int>& price, int n) {
        // Initialize DP table with dimensions [n + 1]
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int length = 0; length <= n; length++){
            prev[length] = price[0]*length;
        }
        
        // Fill the DP table
        for (int ind = 1; ind < n; ++ind) { 
            for (int length = 1; length <= n; ++length) { 
                
                // Case when the piece is not taken
                int notTaken = 0+prev[length];
                
                // Case when the piece is taken
                int taken = INT_MIN;
                
                /* Length of the rod piece 
                corresponding to the current index*/
                int rodLength = ind + 1;
                
                // Check if the piece can be taken
                if (rodLength <= length) {
                    taken = price[ind] + cur[length - rodLength];
                }
                
                /* Update cur[length] with the maximum of 
                including or not including the current piece*/
                cur[length] = max(notTaken, taken);
            }
            prev = cur;
        }
        
        // Return the result 
        return prev[n];
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n)
