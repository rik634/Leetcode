// problem statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. 
//A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
//Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
//As there can be many peak values, 1 is given as output if the returned index is a peak number, otherwise 0.

// binary search
class Solution {
  public:
    
      int maxElement(vector<vector<int>>& arr, int col) {
          int n = arr.size();
          int max_val = INT_MIN;
          int index = -1;
          for (int i = 0; i < n; i++) {
              if (arr[i][col] > max_val) {
                  max_val = arr[i][col];
                  index = i;
              }
          }
          return index;
      }

      vector<int> findPeakGrid(vector<vector<int>>& arr) {
          int n = arr.size();     
          int m = arr[0].size();  
          int low = 0;           
          int high = m - 1;      

          while (low <= high) {
              int mid = (low + high) / 2;
              int row = maxElement(arr, mid);
              int left = mid - 1 >= 0 ? arr[row][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? arr[row][mid + 1] : INT_MIN;

              if (arr[row][mid] > left && arr[row][mid] > right) {
                  return {row, mid};
              } 
              else if (left > arr[row][mid]) {
                  high = mid - 1;
              } 
              else {
                  low = mid + 1;
              }
          }
          return {-1, -1};
      }
  };
// time complexity: O(n*logm)
// space complexity:O(1)
