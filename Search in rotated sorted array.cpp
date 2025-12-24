// level: Medium
// brute force
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time complexity: O(n)
// space complexity: O(1)

// binary search (optimized)
class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int k=0;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && nums[mid]>target)
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(nums[r]>=target && nums[mid]<target)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
// Time complexity: O(nlogn)
// space complexity: O(1)
