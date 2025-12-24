// level: Medium
// brute force
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=-1;
        int r=-1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                if(l==-1)
                {
                    l=i;
                    r=i;
                }
                else
                {
                    r=i;
                }
            }
        }
        return {l,r};
    }
};
// Time complexity: O(n)
// space complexity: O(1)

// binary search 
class Solution {
public:
    int lower_bound(vector<int>& nums, int target, int& n)
    {
        int l=0;
        int r=n-1;
        int ind=n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>=target)
            {
                ind=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n==0)
        {
            return {-1,-1};
        }
        int lower = lower_bound(nums,target,n);
        int upper = lower_bound(nums,target+1,n)-1;
        if(lower<n && nums[lower]==target  )
        {
            return {lower,upper};
        }
        return {-1,-1};

    }
};
// time complexity: O(nlogn)
// space complexity: O(1)
