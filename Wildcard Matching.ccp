// Level: hard
// Recursion
class Solution {
public:
    bool f(int i,int j, string& s, string& p)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i<0 && j>=0)
        {
             for(int k=j;k>=0;k--)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
            
        }
        if(j<0 && i>=0)
        {
           return false;
        }
        if(s[i]==p[j] || p[j]=='?')
        {
            return f(i-1,j-1,s,p);
        }
        if(p[j]=='*')
        {
            return f(i-1,j,s,p) || f(i,j-1,s,p);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return f(n-1,m-1,s,p);
    }
};
// Time complexoty: exponential
// Space complexity: O(N+M)

// memoization
class Solution {
public:
    bool f(int i,int j, string& s, string& p, vector<vector<int>>& dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i<0 && j>=0)
        {
             for(int k=j;k>=0;k--)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
            
        }
        if(j<0 && i>=0)
        {
           return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*')
        {
            return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};

// time complexity: O(N*M)
// space complexity: O(N*m) + o(N+M) (auxiliary stack space)

// memoization with 1-based indexing
class Solution {
public:
    bool f(int i,int j, string& s, string& p, vector<vector<int>>& dp)
    {
        if(i==0 && j==0)
        {
            return true;
        }
        if(i==0 && j>0)
        {
             for(int k=j;k>0;k--)
            {
                if(p[k-1]!='*')
                {
                    return false;
                }
            }
            return true;
            
        }
        if(j==0 && i>0)
        {
           return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i-1]==p[j-1] || p[j-1]=='?')
        {
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }
        if(p[j-1]=='*')
        {
            return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};

// tabulation
class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++)
        {
            dp[0][j]=true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    dp[0][j]=false;
                    break;
                }
            }
           
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                     dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

// - Time complexity: O(N*M)
// - Space Complexity: O(N*M)

// space optimized
class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<bool> prev(m+1,false);
        prev[0]=true;
        for(int j=1;j<=m;j++)
        {
            prev[j]=true;
            for(int k=1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    prev[j]=false;
                    break;
                } 
            }
           
        }
        for(int i=1;i<=n;i++)
        {
            vector<bool> temp(m+1,false);
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                     temp[j]=prev[j-1];
                }
                else if(p[j-1]=='*')
                {
                    temp[j]=prev[j] || temp[j-1];
                }
            }
            prev=temp;
        }
        return prev[m];
    }
};

// - Time complexity: O(N*M)
// - space complexity: O(M)
