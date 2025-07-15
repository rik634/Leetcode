// Level: Medium
// Recursion
class Solution {
  public:
    int f(int l, int r, vector<int>& arr)
    {
        if(l==r)
        {
            return 0;
        }
        int mn=1e9;
        for(int k=l;k<=r-1;k++)
        {
            int steps = arr[l-1]*arr[k]*arr[r] + f(l,k,arr)+ f(k+1,r,arr);
            mn=min(mn,steps);
        }
        return mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        return f(1,n-1,arr);
    }
};

// - Time Complexity: O(n^3)
// - Space Complexity: O(1) 

// Memoization
class Solution {
  public:
    int f(int l, int r, vector<int>& arr,vector<vector<int>>& dp)
    {
        if(l==r)
        {
            return 0;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int mn=1e9;
        for(int k=l;k<=r-1;k++)
        {
            int steps = arr[l-1]*arr[k]*arr[r] + f(l,k,arr,dp)+ f(k+1,r,arr,dp);
            mn=min(mn,steps);
        }
        return dp[l][r]=mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
    }
};
// - Time Complexity: O(n^3)
// - Space Complexity: O(n^2) for the dp array  + O(n) (auxiliary stack space)


// Tabulation
class Solution {
  public:
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int mn=1e9;
                for(int k=i;k<=j-1;k++)
                {
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k]+ dp[k+1][j];
                    mn=min(mn,steps);
                }
                dp[i][j]=mn;
            }
        }
        return dp[1][n-1];
    }
};

// - Time Complexity: O(n^3)
// - Space Complexity: O(n^2) for the dp array

// Space Optimied
class Solution {
  public:
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n,0);
        for(int i=n-1;i>0;i--)
        {
            vector<int> temp(n,0);
            for(int j=i+1;j<n;j++)
            {
                int mn=1e9;
                for(int k=i;k<=j-1;k++)
                {
                    int steps = arr[i-1]*arr[k]*arr[j] + dp[k]+ temp[j];
                    mn=min(mn,steps);
                }
                temp[j]=mn;
            }
            dp=temp;
        }
        return dp[n-1];
    }
};

// - Time Complexity: O(n^3)
// - Space Complexity: O(n) for the dp array   

