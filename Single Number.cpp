// Level: Easy
// Link: https://leetcode.com/problems/single-number/description/
// Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num =0;
        for(int i=0;i<nums.size();i++)
        {
            num = num ^ nums[i];
        }
        return num;
    }
};
// Time Complexity: O(N) (N = Number of elements in array)
// Space Complexity: O(1)

// if the array is already sorted, this can be optimized further
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Check if mid is the first element of a pair
            // (mid ^ 1) trick: 
            // If mid is even, mid^1 is mid+1. 
            // If mid is odd, mid^1 is mid-1.
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1; // We are in the left half, move right
            } else {
                high = mid - 1; // We are in the right half, move left
            }
        }
        return nums[low];
    }
};
// time complexity: O(logn)
// space complexity:O(1)
