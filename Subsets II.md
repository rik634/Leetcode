## Problem statement
- Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
- The solution set must not contain duplicate subsets. Return the solution in any order.

### Brute force
- use set to store the unique subsets
```cpp
class Solution {
public:
    void findSubset(int ind, vector<int>& nums, set<vector<int>>& st,
                    vector<int> curr) {
        if (ind == nums.size()) {
            st.insert(curr);
            return;
        }
        // notTake
        findSubset(ind + 1, nums, st, curr);
        // take
        curr.push_back(nums[ind]);
        findSubset(ind + 1, nums, st, curr);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> st;
        vector<int> curr;
        findSubset(0, nums, st, curr);
        for (auto it : st) {
            res.push_back(it);
        }
        return res;
    }
};
```
- Time complexity: O(2^n)* O(n) (curr, copying into temp storage) * O(log(2^n)))(inserting into set, which is balanced BST based set)  = O(n*n*(2^n))
- Space complexity: O(n) + O(2^n)*O(n) (each vector can be with max n elements)= O(n*(2^n))

### Optimal
```cpp
class Solution {
public:
    void findSubset(int ind, vector<int>& nums, vector<vector<int>>& res,
                    vector<int> curr) {
        
        res.push_back(curr);
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
            {
                continue;
            }
            curr.push_back(nums[i]);
            findSubset(i+1,nums,res,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        findSubset(0, nums, res, curr);

        return res;
    }
};
```
- Time complexity: O(n*(2^n))
- Space complexity: O(n)
