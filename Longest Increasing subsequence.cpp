// level: medium
// recursion
class Solution {
public:
    int f(int ind, int prev, vector<int>& nums)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        int notTake = 0 + f(ind+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
        {
            take = 1 + f(ind+1,ind,nums);
        }
        return max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        return f(0,-1,nums);
    }
};
// - Time Complexity: O(2^n) (for each element, we have two choices: take or not take)
// - Space Complexity: O(n) (for the recursion stack)

// memoization
class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(dp[ind][prev+1]!=-1)
        {
            return dp[ind][prev+1];
        }
        int notTake = 0 + f(ind+1,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
        {
            take = 1 + f(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0,-1,nums,dp);
    }
};


// - Time Complexity: O(n*(n+1)) (as we are storing the results of subproblem)
// - Space Complexity: O(n*(n+1)) + O(n) (auxiliary space for recursion stack) = O(n^2) (for the dp array)

// tabulation
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int notTake = 0 + dp[ind+1][prev+1];
                int take=0;
                if(prev==-1 || nums[ind]>nums[prev])
                {
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};


// - Time Complexity: O(n^2) (as we are storing the results of subproblem)
// - Space Complexity: O(n^2) (for the dp array)   

// space optimized
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prev1(n+1, 0);
        vector<int> temp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                int notTake = 0 + prev1[prev+1];
                int take=0;
                if(prev==-1 || nums[ind]>nums[prev])
                {
                    take = 1 + prev1[ind+1];
                }
                temp[prev+1] = max(take, notTake);
            }
            prev1=temp;
        }
        return prev1[0];
    }
};

// - Time Complexity: O(n^2) (as we are storing the results of subproblem)
// - Space Complexity: O(n) (for the dp array) 

// tabulation (intuition)
class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
       int lis[n];
    lis[0]=1;
    int res=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
        res = max(res, lis[i]);
    }
    
    
    return res;
    }
};

// - Time Complexity: theta(n^2)
// - Space Complexity: theta(n)


// using binary search
class Solution {
public:
    int ceilInd(vector<int> lis, int s, int e, int x)
{
    while(s<e)
    {
        int m = s + (e-s)/2;
        if(lis[m]>=x)
        {
            e=m;
        }
        else
        {
            s=m+1;
        }
    }
    return s;
}
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> lis;
        int n = nums.size();
        lis.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>lis.back())
            {
                lis.push_back(nums[i]);
                len++;
            }
            else
            {
                // binary search
                int c = ceilInd(lis,0,len-1,nums[i]);
                lis[c]=nums[i];
            }
        }
        return len;
    }
};
// - Time Complexity: O(nlog n)
// - Space Complexity: theta(n)
