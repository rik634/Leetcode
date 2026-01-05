// level: Hard
// problem statement: Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. 
//You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window..

// brute force:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= (n - k); i++) {
            int mx = INT_MIN;
            for (int j = i; j < (i + k); j++) {
                mx = max(mx, nums[j]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
// time complexity: O((n-k)*k) =   O(n*k) Each of the (n - k + 1) windows is scanned completely to find its maximum. In worst-case, each window of size k requires O(k) operations.
// space complexity:  O(1) We are only using output list which does not count as extra space in space complexity analysis. No additional data structures used.


// optimized
