// level: easy
// brute force, linear search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }
};
// time complexity: O(n)
// space complexity: O(1)

// binary search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
       int l=0;
       int r=n-1;
       while(l<=r)
       {
        int mid = (l+r)/2;
         int miss = arr[mid]-(mid+1);
         if(miss<k)
         {
            l=mid+1;
         }
         else
         {
            r=mid-1;
         }
       }
       return k+r+1;
    }
};
// Time complexity: O(logn)
// space complexity: O(1)
