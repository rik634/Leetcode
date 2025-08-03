// level: hard
// link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int n = fruits.size();
        vector<int> sum(n+1,0);
        vector<int> indices(n,0);
        for(int i=0;i<n;i++)
        {
            sum[i+1]=sum[i]+fruits[i][1]; // prefix sum
            indices[i]=fruits[i][0];
        }
        int total=0;
        for(int x=0;x<=k/2;x++)
        {
            int y = k-2*x;
            int leftPos = startPos-x;
            int rightPos = startPos+y;
            int start = lower_bound(indices.begin(),indices.end(),leftPos)-indices.begin();
            int end = upper_bound(indices.begin(),indices.end(),rightPos)-indices.begin();

            total = max(total,sum[end]-sum[start]);

            leftPos = startPos-y;
            rightPos = startPos+x;
            start = lower_bound(indices.begin(),indices.end(),leftPos)-indices.begin();
            end = upper_bound(indices.begin(),indices.end(),rightPos)-indices.begin();

            total = max(total,sum[end]-sum[start]);
        }
        return total;

    }
};
// time complexity = O(n+klogn)
// space complexity: O(n)
