// level: Mediium
// problem statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. 
//Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

// brute force
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;

    }
};
// time complexity: O(m*n)
// space complexity : O(1)

// space optimized + binary search 
class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int& row, int &target, int&m, int & n)
    {
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(matrix[row][mid]==target)
            {
                return true;
            }
            else if(matrix[row][mid]<target)
            {
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
           if(matrix[i][0]<=target && matrix[i][n-1]>=target)
           {
              if(binarySearch(matrix,i,target,m,n))
              {
                return true;
              }
           }
        }
        return false;

    }
};
// time complexity: O(m*logn)
// space complexity: O(1)

// binary search 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while (low <= high) {
           
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
// time complexity: O(log(m*n))
// space complexity: O(1)
