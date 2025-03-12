//level:easy
//link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
//time complexity: O(logn)
//space complexity: O(1)

//solution

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n = nums.size();
        int index=0;
        int l=0,r=n-1;
        int neg=0;
        int pos=0;
        while(l<=r && (nums[l]!=0 || nums[r]!=0))
        {
            if(nums[l]<0)
            {
                l++;
                neg++;
            }
            if(nums[r]>0)
            {
                r--;
                pos++;
            }
        }
        return max(neg,pos);
    }
};
