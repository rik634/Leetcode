// level: Hard
// problem statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain .

// brute force:
class Solution {
public:
    // Function to calculate trapped rainwater using brute force approach
    int trap(vector<int>& height) {
        int n = height.size();
        // Variable to store total trapped water
        int totalWater = 0;       
        // Iterate over each bar in the elevation map
        for (int i = 0; i < n; i++) {
            // Initialize max heights to the left and right of current bar
            int maxLeft = 0;
            int maxRight = 0;            
            // Find maximum height to the left of current bar
            for (int j = 0; j <= i; j++) {
                if (height[j] > maxLeft) {
                    maxLeft = height[j];
                }
            }            
            // Find maximum height to the right of current bar
            for (int j = i; j < n; j++) {
                if (height[j] > maxRight) {
                    maxRight = height[j];
                }
            }      
            // Water trapped on current bar is min of maxLeft and maxRight minus current height
            totalWater += min(maxLeft, maxRight) - height[i];
        }
        // Return total trapped water
        return totalWater;
    }
};
//Time Complexity: O(n²) because for each bar, we scan all bars to its left and right to find the maximum height, resulting in nested loops.
//Space Complexity: O(1) as no additional data structures are used proportional to input size, only variables to track max heights and total water.

// optimized
class Solution {
public:
    // Function to calculate trapped rainwater using the optimal two-pointer approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Initialize two pointers at both ends of the array
        int left = 0;
        int right = n - 1;
        
        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;
        
        // Variable to store total trapped water
        int totalWater = 0;
        
        // Iterate until left pointer meets right pointer
        while (left <= right) {
            // If left bar is smaller or equal to right bar
            if (height[left] <= height[right]) {
                // If current left bar is higher than maxLeft, update maxLeft
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    // Water trapped on left is difference between maxLeft and current height
                    totalWater += maxLeft - height[left];
                }
                left++; // Move left pointer to the right
            } else {
                // If current right bar is higher than maxRight, update maxRight
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    // Water trapped on right is difference between maxRight and current height
                    totalWater += maxRight - height[right];
                }
                right--; // Move right pointer to the left
            }
        }
        
        // Return total trapped water
        return totalWater;
    }
};
// time complexity: O(n) because the two pointers traverse the array only once, each pointer moving inward and covering the entire array in total linear time.
// space complexity: O(1) as only constant extra space is used for pointers and variables, regardless of input size.
