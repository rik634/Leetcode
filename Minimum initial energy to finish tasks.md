## Problem statement
- You are given an array tasks where tasks[i] = [actuali, minimumi]:
  - actuali is the actual amount of energy you spend to finish the ith task.
  - minimumi is the minimum amount of energy you require to begin the ith task.
- For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.
- You can finish the tasks in any order you like.
- Return the minimum initial amount of energy you will need to finish all the tasks.

### Solution
```cpp
class Solution {
public:
    static bool myComp(const vector<int>& a, const vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), myComp);
        int initial = tasks[0][1];
        int bal = tasks[0][1] - tasks[0][0];
        int extra = 0;
        for (int i = 1; i < n; i++) {

            if (tasks[i][1] > bal) {
                extra += (tasks[i][1] - bal);
                bal = tasks[i][1];
            }
            bal -= tasks[i][0];
        }
        return initial + extra;
    }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(1)

### another
```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        int ans = 0;
        for (auto task : tasks) {
            ans = max(ans + task[0], task[1]);
        }
        return ans;
    }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(1)
