// problem statement: Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

// solution
class Solution {
private:
    // Helper function to count subsequences
    // with the target sum
    int func(int ind, int sum, vector<int> &nums) {
        // Base case: if sum is 0, one valid
        // subsequence is found
        if (sum == 0) return 1;
        // Base case: if sum is negative or 
        // index exceeds array size
        if (sum < 0 || ind == nums.size()) return 0;
        // Recurse by including current number
        // or excluding it from the sum
        return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
    }

public:
    // Function to start counting subsequences
    int countSubsequenceWithTargetSum(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};

// time complexity: O(2^n)
// space complexity:O(n)
