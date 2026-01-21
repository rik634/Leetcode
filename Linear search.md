## problem statement
- Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

### Solution
```cpp
int search(int arr[], int n, int num)
{
    int i;

    // Loop through the array to find the number
    for(i = 0; i < n; i++)
    {
        // If the current element matches the number, return its index
        if(arr[i] == num)
            return i;
    }

    // If the number is not found, return -1
    return -1;
}
```
- Time complexity: O(n)
- Space complexity: O(1)
