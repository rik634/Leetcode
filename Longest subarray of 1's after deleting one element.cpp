// level: Medium
// sliding window approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int curr=0;
        int mx=0;
        while(r<n)
        {
            mp[nums[r]]++;
            if(mp[0]>1 && mp.find(0)!=mp.end())
            {
                mp[nums[l]]--;
                l++;
            }
            if(mp[0]<1)
            {
              mx=max(mx,r-l+1);
            }
            r++;
        }
        return mx-1;
    }
};
// time complexity: O(n)
// space complexity: O(1)

// optimal space approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int l=0;
        int r=0;
       
        int curr=0;
        int mx=0;
        int zero=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                zero++;
            }
            if(zero>1)
            {
                if(nums[l]==0)
                {
                    zero--;
                }
                l++;
            }
            if(zero<=1)
            {
              mx=max(mx,r-l+1);
            }
            r++;
        }
        return mx-1;
    }
};

// optimal
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int l=0;
        int r=0;
       
        int curr=0;
        int mx=0;
        int zero=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                zero++;
            }
            while(zero>1)
            {
                if(nums[l]==0)
                {
                    zero--;
                }
                l++;
            }
            if(zero<=1)
            {
              mx=max(mx,r-l+1);
            }
            r++;
        }
        return mx-1;
    }
};
