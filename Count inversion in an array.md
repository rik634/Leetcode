## Problem statement
- Given an array of N integers, count the inversion of the array (using merge-sort).
- Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

### Brute force
```cpp
int numberOfInversions(vector<int>& a, int n) {
    int cnt = 0; // Initialize inversion count
    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++; // Increment count if inversion found
        }
    }
    return cnt; // Return total inversions
}
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Optimal
- Essentially, it measures "how far" an array is from being sorted.The code uses a modified Merge Sort algorithm to count these inversions in O(n*log n) time.
```cpp
int merge(vector<int> &arr, int low, int mid, int high) {

    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // All remaining left elements are inversions
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}
// Merge sort function that counts inversions
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left half
    cnt += mergeSort(arr, low, mid);
    // Count inversions in right half
    cnt += mergeSort(arr, mid + 1, high);
    // Count inversions during merge
    cnt += merge(arr, low, mid, high);

    return cnt;
}

int numberOfInversions(vector<int>& a, int n) {
    return mergeSort(a, 0, n - 1);
}
```
- Time complexity: O(n*logn)
- Space complexity: O(n)
