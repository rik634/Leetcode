## Problem statement
- Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

### Brute force
```cpp
void getElements(int arr[], int n)
{
    // Edge case when the array has less than 2 elements
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // Print -1 for both second smallest and second largest if the array has less than 2 elements
    
    // Sort the array to easily find the second smallest and second largest elements
    sort(arr, arr + n);

    // Second smallest element is at index 1 after sorting
    int small = arr[1]; 

    // Second largest element is at index n-2 after sorting
    int large = arr[n - 2]; 

    // Output the second smallest and second largest elements
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}
```
- Time complexity: O(nlogn)
- Space complexity: O(1)

### Better approach
```cpp
void getElements(int arr[], int n)
{
    // Edge case: when the array has less than 2 elements
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // If only one element, print -1 for both second smallest and second largest

    // Initialize variables to track the smallest, second smallest, largest, and second largest elements
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;

    // Find the smallest and largest elements in the array
    for (i = 0; i < n; i++) {
        small = min(small, arr[i]);  // Update the smallest element
        large = max(large, arr[i]);  // Update the largest element
    }

    // Find the second smallest and second largest elements
    for (i = 0; i < n; i++) {
        // If the current element is smaller than second_small and not equal to the smallest, update second_small
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        
        // If the current element is larger than second_large and not equal to the largest, update second_large
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    // Output the second smallest and second largest elements
    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}
```
- Time complexity: O(n) + O(n)
- Space complexity: O(1)

### Optimized
### Logic:
We will need four variables: small, second_small, large, and second_large. Initialize small and second_small to INT_MAX, and large and second_large to INT_MIN.
 - Second Smallest Algorithm:
    1. If the current element is smaller than 'small', update the values of second_small and small.
    2. Else if the current element is smaller than 'second_small', update the value of second_small.
    3. After traversing the array, the second smallest element will be stored in the variable second_small.
 - Second Largest Algorithm:
   1. If the current element is larger than 'large', update the values of second_large and large.
   2. Else if the current element is larger than 'second_large', update the value of second_large.
   3. After traversing the array, the second largest element will be stored in the variable second_large.

```cpp
int secondSmallest(int arr[], int n) {
    // Edge case: if the array has fewer than 2 elements
    if (n < 2)
        return -1;

    int small = INT_MAX;
    int second_small = INT_MAX;

    // Loop through the array to find the second smallest element
    for (int i = 0; i < n; i++) {
        // Update the smallest and second smallest values
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } 
        else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    return second_small; // Return the second smallest element
}

// Function to find the second largest element in the array
int secondLargest(int arr[], int n) {
    // Edge case: if the array has fewer than 2 elements
    if (n < 2)
        return -1;

    int large = INT_MIN, second_large = INT_MIN;

    // Loop through the array to find the second largest element
    for (int i = 0; i < n; i++) {
        // Update the largest and second largest values
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } 
        else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    return second_large; // Return the second largest element
}

```
- Time complexity:O(n)
- Space complexity: O(1)
