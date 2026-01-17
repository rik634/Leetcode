
## problem statement: 
- A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array.
- He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
- We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack .

### logic: 
- The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in data. 
- While selecting a local better choice we may choose an item that will in long term give less value.
-  As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which gives us the maximum value in the given constraints.

### recursive solution:
```cpp
class Solution {
public:
   
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W) {
        // Base case: if we're at the first item
        if (ind == 0) {
            // Calculate and return the maximum value for the given weight limit
            return (W / wt[0]) * val[0];
        }
        // Calculate the maximum value without taking the current item
        int notTaken = knapsackUtil(wt, val, ind - 1, W);

        // Initialize 'taken' with a very small value
        int taken = INT_MIN;

        // If current item can fit in the remaining capacity
        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind]);

        // Store and return the maximum of taking or not taking the current item
        return max(notTaken, taken);
    }

    // Main function to call the utility function and set up DP table
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Call the recursive function and return the answer
        return knapsackUtil(wt, val, n - 1, W);
    }
};
```
- Time complexity: O(2^(n+W))
- space complexity: O(n+W) (recursive stack space)

### Memoization:
```cpp
class Solution {
public:
   
    int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W) {
        // Base case: if we're at the first item
        if (ind == 0) {
            // Calculate and return the maximum value for the given weight limit
            return (W / wt[0]) * val[0];
        }
        // Calculate the maximum value without taking the current item
        int notTaken = knapsackUtil(wt, val, ind - 1, W);

        // Initialize 'taken' with a very small value
        int taken = INT_MIN;

        // If current item can fit in the remaining capacity
        if (wt[ind] <= W)
            taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind]);

        // Store and return the maximum of taking or not taking the current item
        return max(notTaken, taken);
    }

    // Main function to call the utility function and set up DP table
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Call the recursive function and return the answer
        return knapsackUtil(wt, val, n - 1, W);
    }
};
```
- Time complexity: O(n*W)
- space complexity: O(n*W) + O(n+W)

### Tabulation:
```cpp
class Solution {
public:
    // Function to solve the unbounded knapsack problem using tabulation
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Create a DP table where dp[i][j] represents max value using first i items and capacity j
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base condition: fill first row considering infinite supply of first item
        for (int i = wt[0]; i <= W; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }

        // Loop through all items starting from second
        for (int ind = 1; ind < n; ind++) {
            // Loop through all capacities from 0 to W
            for (int cap = 0; cap <= W; cap++) {
                // Case 1: Not taking the current item
                int notTaken = dp[ind - 1][cap];

                // Case 2: Taking the current item (if it fits)
                int taken = INT_MIN;
                if (wt[ind] <= cap)
                    taken = val[ind] + dp[ind][cap - wt[ind]];

                // Store the best of both choices
                dp[ind][cap] = max(notTaken, taken);
            }
        }

        // Return the maximum value possible for n items and capacity W
        return dp[n - 1][W];
    }
};
```
- Time complexity: O(n*W)
- Space complexity: O(n*W)

### Space optimized
```cpp
class Solution {
public:
    // Function to solve the unbounded knapsack problem using space-optimized DP
    int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
        // Create a 1D DP array where cur[cap] stores max value for given capacity
        vector<int> cur(W + 1, 0);

        // Base condition: fill values for first item
        for (int i = wt[0]; i <= W; i++) {
            cur[i] = (i / wt[0]) * val[0];
        }

        // Iterate through remaining items
        for (int ind = 1; ind < n; ind++) {
            for (int cap = 0; cap <= W; cap++) {
                // Option 1: Not take current item
                int notTaken = cur[cap];

                // Option 2: Take current item (if it fits)
                int taken = INT_MIN;
                if (wt[ind] <= cap) {
                    taken = val[ind] + cur[cap - wt[ind]];
                }

                // Store the better option
                cur[cap] = max(notTaken, taken);
            }
        }

        // Return max value for capacity W
        return cur[W];
    }
};
```
- Time complexity: O(n*W)
- Space complexity: O(W)
