## Problem statement
- Given an array of integers arr, you are initially positioned at the first index of the array.
- In one step you can jump from index i to index:
  - i + 1 where: i + 1 < arr.length.
  - i - 1 where: i - 1 >= 0.
  - j where: arr[i] == arr[j] and i != j.
- Return the minimum number of steps to reach the last index of the array.
- Notice that you can not jump outside of the array at any time.

### Solution
```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].insert(i);
        }
        int step = -1;
        queue<int> q;
        vector<bool> vis(n, false);
        vis[0] = true;
        q.push(0);
        while (!q.empty()) {
            int size = q.size();
            step++;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if (p == n - 1) {
                    return step;
                }
                int ind = p;
                int val = arr[p];
                if (ind + 1 < n && vis[ind + 1] == false) {
                    q.push(ind + 1);
                    vis[ind + 1] = true;
                }
                if (ind - 1 >= 0 && vis[ind - 1] == false) {
                    q.push(ind - 1);
                    vis[ind - 1] = true;
                }
                for (auto it : mp[val]) {
                    if (it != ind && vis[it] == false) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
                mp.erase(val);
            }
        }
        return 0;
    }
};
```
- Time complexity: O(n)
- Space compleity: O(n)
