// problem statement: Given an array with N positive integers and an integer D, count the number of ways we can partition the given array into two subsets, S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.
// logic:
//So, S1 = (d + totalSum) / 2
//There are some conditions to check before solving:
// 1. If (d + totalSum) is odd, then division by 2 is not possible, thus, there is no valid partitions
//  2. If d is greater than totalSum, then it is also impossible, thus, there is no valid partitions

// solution:
class Solution {
public:
    // Function to count partitions with given difference
    int countPartitions(vector<int>& arr, int d) {
        // Calculate total sum of array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // Check if solution is possible
        if ((totalSum + d) % 2 != 0 || d > totalSum) return 0;

        // Calculate target sum
        int K = (totalSum + d) / 2;

        // Create dp array of size K+1
        vector<int> dp(K + 1, 0);

        // Base case: empty set makes sum 0
        dp[0] = 1;

        // If first element <= K, mark it
        if (arr[0] <= K) dp[arr[0]] += 1;

        // Process remaining elements
        for (int i = 1; i < arr.size(); i++) {
            vector<int> curr(K + 1, 0);
            curr[0] = 1;

            for (int t = 0; t <= K; t++) {
                int notTake = dp[t];
                int take = 0;
                if (arr[i] <= t) {
                    take = dp[t - arr[i]];
                }
                curr[t] = take + notTake;
            }
            dp = curr;
        }
        return dp[K];
    }
};
// Time complexity: O(n*K)
// space complexity: O(k(
