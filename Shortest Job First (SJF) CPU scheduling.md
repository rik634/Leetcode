## Problem statement
- Given a list of job durations representing the time it takes to complete each job. Implement the Shortest Job First algorithm to find the average waiting time for these jobs.

### Logic
- Sort the jobs in ascending order based on their durations. The jobs array will now contain the job durations arranged from shortest to longest.
- Initialise variables waitTime to 0 (waiting time for that particular job) and totalTime (total waiting time for all jobs).
- Iterate through each job in the sorted array. For each job, its waiting time is the sum of total time taken by all previous jobs. Update the total time taken by adding the duration of the current job to the total waiting time.
- After iterating through each job in the array, the average waiting is total waiting time divided by the number of jobs ie. length of the jobs array.After iterating through each job in the array, the average waiting is total waiting time divided by the number of jobs ie. length of the jobs array.

### Solution
```cpp
class ShortestJobFirst {
public:
    float calculateAverageWaitTime(vector<int>& jobs) {
        sort(jobs.begin(), jobs.end());

        float waitTime = 0;  // Stores cumulative waiting time
        int totalTime = 0;   // Tracks elapsed execution time
        int n = jobs.size(); 

        for (int i = 0; i < n; i++) {
            waitTime += totalTime;  
            totalTime += jobs[i];   
        }
        return waitTime / n;
    }
};
```
- Time complexity: O(nlogn) + O(n)
- Space complexity: O(1)
