//Level: easy
//Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/
//Solution
int minOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_set<int> s;
        
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
            mn=min(mn,nums[i]);
        }
        int distinct=s.size();
        if(mn<k)
        {
            return -1;
        }
        else if(mn==k)
        {
            return distinct-1;
        }
        return distinct;
    }
