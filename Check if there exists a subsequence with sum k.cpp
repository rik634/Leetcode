// problem statement: Given an array nums and an integer k. Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.
// solution:
class Solution {
private:
    // This method recursively checks for the subsequence with the given sum
    bool func(int ind, int sum, std::vector<int> &nums) {
        // Base case: if all elements are processed, check if sum is 0
        if (ind == nums.size()) {
            return sum == 0;
        }
        // Recursive call: include the current element in the subsequence
        // or exclude the current element from the subsequence
        return func(ind + 1, sum - nums[ind], nums) | func(ind + 1, sum, nums);
    }

public:
    // This method initiates the recursive process
    bool checkSubsequenceSum(std::vector<int>& nums, int target) {
        return func(0, target, nums); // Start the recursive process
    }
};
// time complexity: O(2^n)
// space complexity:O(n)
