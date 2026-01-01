// level: Medium
// problem statement: Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
//The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
//It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// solution: 
class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& res, vector<int> ans)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                res.push_back(ans);
            }
            return;
        }
        if(candidates[index]<=target)
        {
            ans.push_back(candidates[index]);
            findCombinations(index,target-candidates[index],candidates,res,ans);
            ans.pop_back();
        }
        findCombinations(index+1,target,candidates,res,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> ans;
        findCombinations(0,target,candidates,res,ans);
        return res;
    }
};
// time complexity: O((2^t) * k) due to exploring all combinations up to the target with copying each valid combination of average length k.
// space complexity: O(k * x) to store all valid combinations, where x is the number of combinations and k is their average length.
