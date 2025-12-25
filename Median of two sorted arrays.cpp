// level: Hard
// problem statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. 
//The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements
// brute force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        vector<int> dp(m+n,0);
        int i=0;
        int j=0;
        int index=0;
        while(i<m && j<n)
        {
           
            if(nums1[i]<=nums2[j])
            {
                dp[index]=nums1[i];
                i++;
                index++;
            }
            else 
            {
                dp[index]=nums2[j];
                j++;
                index++;
            }
        }
        while(i<m)
        {
            dp[index]=nums1[i];
            i++;
            index++;
        }
        while(j<n)
        {
            dp[index]=nums2[j];
            j++;
            index++;
        }
        int t = m+n;
        if(t%2!=0)
        {
            return (double)dp[t/2];
        }
        return (double)(dp[t/2]+dp[(t/2)-1])/2;
    }
};
// time complexity: O(m+n)
// space complexity: O(m+n)

// space optimized
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();
        int ind1=(m+n)/2;
        int a=0;
        int b=0;
        int ind2=ind1-1;
        int i=0;
        int j=0;
        int index=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j]){
                if(index==ind1){
                    a=nums1[i];
                }
                if(index==ind2){
                    b=nums1[i];
                }
                i++;
            }
            else {
               if(index==ind1){
                    a=nums2[j];
                }
                if(index==ind2){
                    b=nums2[j];
                }
                j++;
            }
            index++;
        }
        while(i<m){
           if(index==ind1){
                    a=nums1[i];
                }
                if(index==ind2){
                    b=nums1[i];
                }
            i++;
            index++;
        }
        while(j<n){
           if(index==ind1)
                {
                    a=nums2[j];
                }
                if(index==ind2)
                {
                    b=nums2[j];
                }
            j++;
            index++;
        }
        int t = m+n;
        if(t%2!=0)
        {
            return (double) a;
        }
        return (double)(a+b)/2;
    }
};
// time complexity: O(m+n)
// space complexity: O(1)

// binary search 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // Ensure a is the smaller array to minimize binary search scope
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);

        int n1 = a.size(), n2 = b.size();
        int low = 0, high = n1;

        // Binary search on the smaller array
        while (low <= high) {
            // Calculate the cut positions for both arrays
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Handle boundary elements using INT_MIN and INT_MAX
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            // If correct partition is found
            if (l1 <= r2 && l2 <= r1) {
                // Total even => average of max left and min right
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    // Total odd => max of left half
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                // Shift left in a
                high = cut1 - 1;
            }
            else {
                // Shift right in a
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

// time complexity: O(log(min(m,n)))
// space complexity: O(1)
