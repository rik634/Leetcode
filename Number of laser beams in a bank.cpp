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
