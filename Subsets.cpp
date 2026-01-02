// Level: Medium
// problem statement:  Given a string, find all the possible subsequences of the string.

// brute force (bit manipulation)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        int subset = 1 << n ;
        vector<vector<int>> ans;
        for(int i=0;i<subset;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                if(( i & (1 << j)) > 0) // bit is set
                {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
// Time Complexity: O(n*(2^n)) (nested for loops)
// Space Complexity: O(n*(2^n)) (there are total (2^n) subsets, in worst case each subset can have n elements)

// optimized
class Solution {
public:
    void getSubset(int ind, int& n, vector<int> v, vector<vector<int>>& res,vector<int>& nums)
    {
        if(ind==n)
        {
            res.push_back(v);
            return;
        }
        getSubset(ind+1,n,v,res,nums);
        v.push_back(nums[ind]);
        getSubset(ind+1,n,v,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> res;
        getSubset(0,n,{},res,nums);
        return res;
    }
};
// time complexity: O(n*(2^n))
// space complexity:O(n*(2^n))



