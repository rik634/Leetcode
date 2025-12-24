// level: Medium
// brute force
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mn=min(mn,nums[i]);
        }
        return mn;
    }
};
// Time complexity: O(n)
// space complexity: O(1)

// binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return nums[l];
    }
};
// Tiem complexity: O(nlogn)
// space complexity: O(1)
