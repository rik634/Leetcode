// level: Medium
// brute force
class Solution {
public:
    int countDays(vector<int>& weights, int c)
    {
        int count=0;
        int temp=0;
        for(int j=0;j<weights.size();j++)
        {
            if(weights[j]>c)
            {
                return INT_MAX;
            }
            if((temp+weights[j])<=c)
            {
                temp+=weights[j];
            }
            else
            {
                count++;
                temp=weights[j];
            }
        }
        if(temp<=c)
        {
            count++;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int mx=0;
        int mn = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx+=weights[i];
            mn=max(mn,weights[i]);
        }
        for(int i=mn;i<=mx;i++)
        {
            int d = countDays(weights,i);
            if(d<=days)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time complexity: O((sum-mx)*n)
// space complexity: O(1)

// binary search
class Solution {
public:
     int countDays(vector<int>& weights, int c)
    {
        int count=0;
        int temp=0;
        for(int j=0;j<weights.size();j++)
        {
            if(weights[j]>c)
            {
                return INT_MAX;
            }
            if((temp+weights[j])<=c)
            {
                temp+=weights[j];
            }
            else
            {
                count++;
                temp=weights[j];
            }
        }
        if(temp<=c)
        {
            count++;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int mx=0;
        int mn = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx+=weights[i];
            mn=max(mn,weights[i]);
        }
        int l=mn;
        int r=mx;
         int ans=mx;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int count=countDays(weights,mid);
            if(count<=days)
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
// Time complexity: O(n*log(sum-mx)) + O(n) = O(n*(log(sum-mx)+1))
// space complexity: O(1)
