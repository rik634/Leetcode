// level: Medium
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int lsum=0;
        int rsum=0;
        int mx=0;
        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        mx=lsum;
        int r=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            mx=max(mx,lsum+rsum);
        }
        return mx;
    }
};
// Time complexity : O(k) + O(k) = O(2*k)
// space complexity: O(1)
