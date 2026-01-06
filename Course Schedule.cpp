// level: Medium
// problem statement: There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example, to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
//Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

// BFS;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<int> adj[n];
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            count++;
            for (auto it : adj[p]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count == n;
    }
};

// DFS:
class Solution {
public:
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathVis, vector<int> adj[])
    {
        vis[node]=true;
        pathVis[node]=true;
        for(auto it:adj[node])
        {
            if(vis[it]==false)
            {
                if(dfs(it,vis,pathVis,adj)==true)
                {
                    return true;
                }
            }
            else if(pathVis[it]==true)
            {
                return true;
            }
        }
        pathVis[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        

        int n = numCourses;
        vector<int> adj[n];
        vector<bool> vis(n,false);
        vector<bool> pathVis(n,false);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                if(dfs(i,vis,pathVis,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// Time complexity: O(v+E) (build adj list) + O(V) + O(E) (dfs) = O(V+E)
// space complexity: O(V+E) (adj list) + O(V) (vis) + O(V) (recursive stack space) = O(V+E)
