## Problem statement
- Given a chain of matrices A1,..., An denoted by an array of size n+1, find out the minimum number of operations to multiply these n matrices .

### Logic
Rules to solve the problem of partition DP:
  1. Start with the full array: Represent the matrices with indexes i and j. We need to find the minimum cost to multiply matrices from i to j (f(i,j)).
  2. Check the base case: If i == j, there is only one matrix, so return 0 (no multiplication needed).
  3. Try all possible partitions: For k from i to j-1, split the array into two parts: f(i,k) and f(k+1,j).
  4. Calculate cost for each partition: Add the cost of multiplying the two subproblems plus the cost of multiplying their resulting matrices.
  5. Choose the minimum: Keep track of the minimum cost among all partitions.
  6. Return the result: After checking all partitions, return the minimum cost for multiplying matrices from i to j.

### Recursion
```cpp
class Solution {
  public:
    int matrixMin(vector<int>& arr, int i, int j)
    {
        // Base case: if only one matrix is present, no multiplication needed
        if(i==j)
        {
            return 0;
        }
        int mn=INT_MAX;
        // Try all possible partitions
        for(int k=i;k<j;k++)
        {
              // Cost of multiplying matrices from i to k
            int p1 = matrixMin(arr,i,k);
             // Cost of multiplying matrices from k+1 to j
            int p2 = matrixMin(arr,k+1,j);
              // Cost of multiplying the two resulting matrices
            int currCost = arr[i-1]*arr[k]*arr[j];
             // Total cost for this partition
            int total = p1+p2+currCost;
            // Update minimum
            mn=min(mn,total);
        }
        return mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        return  matrixMin(arr,1,n-1);
        
    }
};
```
- Time Complexity: O(2^n) (Exponential) 
   - Strictly speaking, the number of ways to parenthesize n matrices is related to the Catalan Number, which grows at a rate of approximately {4^n}/{n^{1.5}}.
   - Recursion Tree: For every call matrixMin(i, j), the loop runs from i to j-1, splitting the problem into two smaller recursive calls.
   - Overlapping Subproblems: Without memoization, the same (i, j) pairs are calculated repeatedly.
   -  For example, to find the best way to multiply 4 matrices, the function will solve for the sub-chain of the middle 2 matrices multiple times in different branches of the tree.
- Space complexity: O(n) (recursive stack space) + O(1) (auxiliary space)

### Memoization
```cpp
class Solution {
  public:
    int matrixMin(vector<int>& arr, int i, int j,vector<vector<int>>& dp)
    {
        // Base case: if only one matrix is present, no multiplication needed
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn=INT_MAX;
        // Try all possible partitions
        for(int k=i;k<j;k++)
        {
              // Cost of multiplying matrices from i to k
            int p1 = matrixMin(arr,i,k,dp);
             // Cost of multiplying matrices from k+1 to j
            int p2 = matrixMin(arr,k+1,j,dp);
              // Cost of multiplying the two resulting matrices
            int currCost = arr[i-1]*arr[k]*arr[j];
             // Total cost for this partition
            int total = p1+p2+currCost;
            // Update minimum
            mn=min(mn,total);
        }
        return dp[i][j]=mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return  matrixMin(arr,1,n-1,dp);
        
    }
};
```
- Time Complexity: O(n^3). There are O(n^2) subproblems (for each i, j), and for each we try O(n) partitions.
- Space Complexity: O(n^2). We use a 2D dp table of size n x n, plus recursion stack O(n).


### Tabulation
```cpp
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int mn=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int sum = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    mn=min(mn,sum);
                }
                dp[i][j]=mn;
            }
        }
        return  dp[1][n-1];
        
    }
};
```
- Time Complexity:O(n*n*n)
- Space Complexity: O(n^2). We use a 2D dp table of size n x n, plus recursion stack O(n).

### Another tabulation approach
```cpp
class Solution {
public:
    int matrixMultiplication(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // A single matrix needs no multiplication cost
        for (int i = 1; i < n; ++i) {
            dp[i][i] = 0;
        }

        // Filling the dp array
        for (int length = 2; length < n; ++length) { // length of the chain
            for (int i = 1; i <= n - length; ++i) {
                int j = i + length - 1;
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        // The result is in dp[1][n-1]
        return dp[1][n - 1];
    }
};
```
- Time complexity: O(n*n*n)
- Space complexity: O(n*n)
