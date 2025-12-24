// level: Medium
// brute force
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                return true;
            }
        }
        return false;
    }
};
// Time complexity: O(n)
// space complexity: O(1)

// binary search (optimized)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                return true;
            }
           
         // Edge case: all three are equal, we cannot determine which side is sorted
            if(nums[mid]==nums[l] && nums[mid]==nums[r])
            {
                l++;
                r--;
                continue;
            }
             // left half is sorted
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<=nums[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            // right half is sorted
            else {
                if(nums[mid]<=target && target<=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return false;
    }
};
// Time complexity: O(nlogn) for best and average case, O(n/2) for worst case
// space complexity: O(1)
