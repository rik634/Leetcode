## Problem statement


### Brute force
```cpp
class Solution {
public:
    int countPlatforms(int n, int arr[], int dep[]) {
        int ans = 1;
        // Loop over all arrival times
        for (int i = 0; i < n; i++) {
            int count = 1;
            // Check overlap with every other train
            for (int j = i + 1; j < n; j++) {
                // Check if there is overlap between train i and j
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                    (arr[j] >= arr[i] && arr[j] <= dep[i])) {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
```
- Time complexityL O(n*n)
- Space complexity: O(1)

### Optimized
```cpp
class Solution {
public:
    // Function to find minimum platforms required
    int countPlatforms(int n, int arr[], int dep[]) {
        // Sort the arrival and departure times
        sort(arr, arr + n);
        sort(dep, dep + n);

        // Initialize pointers and counters
        int platforms = 1;
        int result = 1;
        int i = 1, j = 0;

        // Traverse both arrays
        while (i < n && j < n) {
            // If next train arrives before current one departs
            if (arr[i] <= dep[j]) {
                // One more platform needed
                platforms++;
                i++;
            } else {
                // One train departs, platform freed
                platforms--;
                j++;
            }

            // Update maximum required platforms
            result = max(result, platforms);
        }

        return result;
    }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(1)
