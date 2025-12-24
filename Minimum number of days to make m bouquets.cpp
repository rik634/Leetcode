// level: Medium
// brute force
class Solution {
public:
    bool countBouquets(vector<int>& bloomDay, int& n, int &m, int &k, int day)
    {
        int count=0;
        int temp=0;
        for(auto it:bloomDay)
        {
            if(it<=day)
            {
                temp++;
            }
            else
            {
                if(temp>=k)
                {
                    count+=(temp/k);
                }
                temp=0;
            }
        }
        if(temp>=k)
        {
            count+=(temp/k);
        }
        return count>=m  ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mn= min(mn,bloomDay[i]);
            mx=max(mx,bloomDay[i]);
        }
        for(int i=mn;i<=mx;i++)
        {
            bool c=countBouquets(bloomDay, n,m,k,i);
            if(c==true)
            {
                return i;
            }
        }
        return -1;
        
       
    }
};
// time complexity: O(n*(mx-mn)( + O(n)
// space complexity: O(1)




// binary search

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mn= min(mn,bloomDay[i]);
            mx=max(mx,bloomDay[i]);
        }
        int l=mn;
        int r=mx;
        int ans=-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int count=0;
            int temp=0;
            for(auto it:bloomDay)
            {
                if(it<=mid)
                {
                    temp++;
                }
                else
                {
                    if(temp>=k)
                    {
                        count+=(temp/k);
                    }
                    temp=0;
                }
            }
            if(temp>=k)
            {
                count+=(temp/k);
            }
           
            if(count>=m)
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
// Time complexity: O(n*log(mx-mn)) + O(n)  = O(n*(log(mx-mn)+1))
// space complexity: O(1)
