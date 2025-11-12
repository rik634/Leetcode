// Level: Medium
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
       int n = nums.size();
       bool flag=false;
       int one=0;
       int gcd=nums[0];
       for(int i=0;i<n;i++)
       {
        gcd=__gcd(gcd,nums[i]);
        if(nums[i]==1)
        {
            one++;
            flag=true;
        }
       }
       if(gcd>1)
       {
        return -1;
       }
       if(flag==true)
       {
        return n-one;
       }

       int mn=n;
       for(int i=0;i<n;i++)
       {
        int g=0;
        for(int j=i;j<n;j++)
        {
            g=__gcd(g,nums[j]);
            if(g==1)
            {
                mn=min(mn,j-i+1);
                break;
            }
        }
       }
       return mn+n-2;
    }
};
// time complexity: O(n*n*logM) (M=max value in nums, logM time is taken for calculating GCD)
// space complexity: O(1)
