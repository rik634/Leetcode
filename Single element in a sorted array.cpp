// level: Medium
// xor
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int num = 0;
        for(int i=0;i<n;i++)
        {
            num=num^nums[i];
        }
        return num;
    }
};
// Time complexity: O(n)
// space complexity: O(1)

// brute force
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
         int n = arr.size();
        if (n == 1) return arr[0];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (arr[i] != arr[i + 1])
                    return arr[i];
            }
            else if (i == n - 1) {
                if (arr[i] != arr[i - 1])
                    return arr[i];
            }
            else {
                if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                    return arr[i];
            }
        }
        return -1;
    }
};
// Time complexity: O(n)
// space complexity: O(1)

// binary search 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2])
        {
            return nums[n-1];
        }
        int l=1;
        int r=n-2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
            {
                return nums[mid];
            }
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1]))
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }
};
// Time complexity: O(logn)
// space complexity: O(1)
