// level:Medium
// problem statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order. 
//But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
// brute force
class Solution {
public:
   
    // Function to search for a target element in the matrix
    bool searchElement(,vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of column
        // Loop through each row
        for (int i = 0; i < n; i++) {
            // Loop through each column in the current row
            for (int j = 0; j < m; j++) {
                // If current element matches the target, return true
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        // If we reach here, target was not found
        return false;
    }
};
// time complexity: O(m*n)
// space complexity: O(1)

// better optimized
class MatrixSearch {
private:
    vector<vector<int>> matrix; // Store the 2D matrix

    bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2; // Middle index
            if (nums[mid] == target) {
                return true; // Target found
            } 
            else if (target > nums[mid]) {
                low = mid + 1; // Search in the right half
            } 
            else {
                high = mid - 1; // Search in the left half
            }
        }
        return false; // Target not found
    }

public:
 
    MatrixSearch(vector<vector<int>>& mat) {
        matrix = mat;
    }
    bool searchElement(int target) {
        int n = matrix.size(); // Number of rows

        // Loop through each row and apply binary search
        for (int i = 0; i < n; i++) {
            if (binarySearch(matrix[i], target)) {
                return true; // Target found in current row
            }
        }
        return false; // Target not found in any row
    }
};

// time complexity: O(n*logm)
// space complexity: O(1)

// BINARY search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0;
        int r=n-1;
        while(l<m  && r>=0)
        {
            if(matrix[l][r]==target)
            {
                return true;
            }
            else if(matrix[l][r]<target)
            {
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};
// time complexity: O(n+m)
//space complexity: O(1)
