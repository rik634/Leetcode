// level: hard
// problem statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'.
//Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array.

// brute force
class Solution {
public:
    int checkIfSplit(vector<int>& nums, int&k, int mnSum)
    {
        int count=0;
        int temp=0;
        for(int i=0;i<nums.size();i++)
        {
            if((temp+nums[i])<=mnSum)
            {
                temp+=nums[i];
            }
            else
            {
                count++;
                temp=nums[i];
            }
        }
        if(temp<=mnSum)
        {
            count++;
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int mx=0;
        int mn=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx+=nums[i];
            mn=max(mn,nums[i]);
        }
        int ans=-1;
        for(int i=mn;i<=mx;i++)
        {
            int c = checkIfSplit(nums,k,i);
            if(c<=k)
            {
                return i;
            }
        }
        return ans;
    }
};
// time complexity: O(n) + O(n*(sum-mx))
// space complexity: O(1)

// binary search:
class Solution {
public:
    int checkIfSplit(vector<int>& nums, int&k, int mnSum)
    {
        int count=0;
        int temp=0;
        for(int i=0;i<nums.size();i++)
        {
            if((temp+nums[i])<=mnSum)
            {
                temp+=nums[i];
            }
            else
            {
                count++;
                temp=nums[i];
            }
        }
        if(temp<=mnSum)
        {
            count++;
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int mx=0;
        int mn=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx+=nums[i];
            mn=max(mn,nums[i]);
        }
        int l=mn;
        int r=mx;
        int ans=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int flag = checkIfSplit(nums,k,mid);
            if(flag<=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
// time complexity: O(n) + O(n*log(sum-mx))
// space complexity: O(1)
