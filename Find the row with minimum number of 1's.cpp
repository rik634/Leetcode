// problem statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. 
//Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1
// brute force:
// Define a class to encapsulate the method
class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;  // Max number of 1s found
        int index = -1;   // Index of row with most 1s

        // Traverse each row of the matrix
        for (int i = 0; i < n; i++) {
            int cnt_ones = 0;  // Count 1s in current row
            for (int j = 0; j < m; j++) {
                cnt_ones += matrix[i][j];
            }
            // Update if this row has more 1s
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

// time complexity: O(n*m)
// space complexity: O(1)


// binary search 
class Solution {
public:
    // Binary search to find the first index where value >= x
    int lowerBound(vector<int> &arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;  // Default if x not found

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;       // Possible answer
                high = mid - 1;  // Look for smaller index
            } else {
                low = mid + 1;   // Search right half
            }
        }
        return ans;
    }

    // Find row with max number of 1s
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(matrix[i], m, 1);  // 1s = total - index of first 1
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};
// time complexity: O(n*(logm))
// space complexity: O(10
