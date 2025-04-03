//level:medium
//link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/
//solution
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       
       int n = nums.size();
       long long res=0;
       long long mx1=0,mx2=0;
       for(int k=0;k<n;k++)
       {
        res = max(res,mx2*nums[k]);
        mx2=max(mx2,mx1-nums[k]);
        mx1=max(mx1,(long long)nums[k]);
       }
       return res;
    }
};
