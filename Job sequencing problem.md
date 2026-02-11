## Problem statement
- You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline.
-  Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

### Logic:
- Sort the jobs in descending order of profit.
- If the maximum deadline is x, create an array of size x. Initialize each array index to -1 to represent that no jobs have been performed yet.
- For each job, check if it can be performed on its last day (i.e., check if the index corresponding to its deadline is available).
- If the job can be performed on its last day, mark that index with the job ID and add the profit to the total.
- If the job cannot be performed on its last day, loop through the previous indexes to find an empty slot and schedule the job there.

### Solution
```cpp
class Solution {
   public:
     
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit); 
      }

   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
        maxi = max(maxi, arr[i].dead);  
      }
      int slot[maxi + 1];
      for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

      int countJobs = 0, jobProfit = 0;
      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {  
                slot[j] = i;  
                countJobs++;  
                jobProfit += arr[i].profit;  
               break;
            }
         }
      }
      return make_pair(countJobs, jobProfit);
   }
};

```
- Time complexity: O(nlogn) + O(n*n)
- Space complexity: O(n)
