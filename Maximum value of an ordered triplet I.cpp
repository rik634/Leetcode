//Level: Easy
//Link:https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/
//solution:
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long sum=0;
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    sum= max(sum, (long long)(nums[i]-nums[j])*nums[k]);
                }
            }
        }
        return sum;
    }
};
