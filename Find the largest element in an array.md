## Problem statement
- Given an array, we have to find the largest element in the array.

### Brute force
```cpp
int sortArr(vector<int>& arr) {
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    
    // Return the last element (largest element) after sorting
    return arr[arr.size() - 1];
}
```
- Time complexity: O(nlogn)
- Space complexity: O(1)

### Optimized
```cpp
int findLargestElement(int arr[], int n) {
    int max = arr[0];  // Initialize max with the first element in the array

    // Iterate through the array to find the maximum element
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {  // If the current element is greater than max, update max
            max = arr[i];
        }
    }

    return max;  // Return the largest element found
}
```
- Time complexity: O(n)
- Space complexity: O(1)
