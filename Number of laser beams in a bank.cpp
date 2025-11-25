// Level: Medium
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:bank[i])
            {
                if(it=='1')
                {
                    dp[i]++;
                }
            }
        }
        int prev=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]!=0)
            {
                count+=(prev*dp[i]);
                prev=dp[i];
            }
        }
        return count;
    }
};
// Time complexity: O(n*m) + O(n)
// Space complexity: O(n)


// space optimized
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        
        int prev=0;
        int count=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr=0;
            for(auto it:bank[i])
            {
                if(it=='1')
                {
                    curr++;
                }
            }

            if(curr!=0)
            {
                count+=(prev*curr);
                prev=curr;
            }
        }
        return count;
    }
};
// Time complexity: O(n*m)
// space complexity: O(1)
