// Level: Medium
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        vector<double> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;i<=maxPts;j++)
            {
                if((i-j)>=0 && (i-j)<k)
                {
                    dp[i]+=dp[i-j]/maxPts;
                }
            }
        }
        return accumulate(dp.begin()+k,dp.end(),0.0);
    }
};
// time complexity: O(n*maxPts)
// space complexity: O(n)

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        vector<double> dp(n+1);
        dp[0]=1;
        double s = k>0 ?1 : 0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=s/maxPts;
            if(i<k)
            {
                s+=dp[i];
            }
            if(i-maxPts>=0 && i-maxPts<k)
            {
                s-=dp[i-maxPts];
            }
        }
        return accumulate(dp.begin()+k,dp.end(),0.0);
    }
};

// time compelxity: O(n)
// space complexity: O(n)
