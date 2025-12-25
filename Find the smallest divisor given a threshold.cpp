// level: Medium
// brute force
class Solution {
public:
    int countRes(vector<int>&nums, int mid)
    {
         int res=0;
            for(int i=0;i<nums.size();i++)
            {
                res+=ceil((double)nums[i]/mid);
            }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int mx=INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
        }
        int ans=mx;
        for(int i=1;i<=mx;i++)
        {
            int r = countRes(nums, i);
            if(r<=threshold)
            {
                return i;
            }
        }
        return ans;
        
    }
};
// time complexity: O(mx*n)
// space complexity: O(1)



// binary search:
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int mx=INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
        }
        int l=1;
        int r=mx;
        int ans=mx;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int res=0;
            for(int i=0;i<n;i++)
            {
                res+=ceil((double)nums[i]/mid);
            }
            if(res<=threshold)
            {
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};
// Time complexity: O(n*log(mx)) + O(n) = O(n*(logmx + 1))
// space complexity: O(1)
