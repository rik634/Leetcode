## Problem statemnt
-  You are given a binary array nums (containing only 0s and 1s) and an integer goal. Return the number of non-empty subarrays of nums that sum to goal. A subarray is a contiguous part of the array.

### Brute force
```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == goal) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Better
```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
          // Add base case: prefix sum 0 has frequency 1
        mp[0]=1;
        int r=0;
        int count=0;
        int curr=0;
        while(r<n)
        {
            curr+=nums[r];
            if(mp.find(curr-goal)!=mp.end())
            {
                count+=mp[curr-goal];
            }
            mp[curr]++;
            r++;
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Optimized
```cpp
class Solution {
public:
    // Function to calculate number of subarrays with sum exactly equal to goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Return difference between subarrays with sum at most goal and at most (goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    // Helper function to compute number of subarrays with sum at most k
    int atMost(vector<int>& nums, int k) {
        // If k is negative, no such subarrays exist
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        // Traverse the array using right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Add current element to sum
            sum += nums[right];

            // Shrink the window from the left if sum exceeds k
            while (sum > k) {
                sum -= nums[left];
                left++;
            }

            // Add the number of valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
};
```
- Time Complexity: O(n), where n is the size of the input array.This is because the algorithm uses the sliding window technique twice (in the two calls to atMost).
    Each `atMost` function runs in linear time , the left and right pointers only move forward, never backward, so the total number of operations is at most 2n.
- Space Complexity: O(1), constant extra space.Only a few integer variables are used .
