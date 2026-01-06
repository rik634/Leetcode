// level: Medium
// problem statement: There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example, to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
//Given the total number of n tasks and a list of prerequisite pairs of size m. Find the order of tasks you should pick to finish all tasks.
//Note: There may be multiple correct orders, you need to return one of them. If it is impossible to finish all tasks, return an empty array.

// DFS:
class Solution {
public:
    bool dfs(int node, stack<int>& st, vector<bool>& vis, vector<bool>& pathVis,
             vector<int> adj[]) {
        vis[node] = true;
        pathVis[node] = true;
        for (auto it : adj[node]) {
            if (vis[it] == false) {
                if (dfs(it, st, vis, pathVis, adj)) {
                    return true;
                }
            } else if (pathVis[it] == true) {
                return true;
            }
        }
        pathVis[node] = false;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<int> res;
        stack<int> st;
        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);
        vector<int> adj[n];
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                if (dfs(i, st, vis, pathVis, adj)) {
                    return {};
                }
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
// Time complexity: O(E) (adj list construction) + O(V+E) (DFS) + O(V) (stack) = O(V+E)
// space complexity; O(V+E)

// BFS:
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<int> res;
        vector<int> adj[n];
        queue<int> q;
        vector<int> indegree(n, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            res.push_back(p);
            for (auto it : adj[p]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (res.size() == n) {
            return res;
        }
        return {};
    }
};
// time complexity: O(V+E)
// space complexity: O(V+E)
