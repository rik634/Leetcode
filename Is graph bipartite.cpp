// level: Medium
// problem statement: 

// BFS:
class Solution {
public:
    bool bfs(int sr, vector<int> adj[], vector<int>& dp) {
        queue<int> q;
        q.push(sr);
        dp[sr] = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (auto it : adj[p]) {
                if (dp[it] == -1) {
                    dp[it] = !dp[p];
                    q.push(it);
                } else if (dp[it] == dp[p]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> dp(n, -1);
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) {
                if (!bfs(i, adj, dp)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// Time complexity: O(2*m) (m=number of edges) + O(n) (n=number of nodes) + O(n) = O(n+2m)
// space complexity: O(n) (dp) + O(n) = O(n)

// DFS
class Solution {
public:
    bool dfs(int sr, vector<int> adj[], vector<int>& dp, int col) {

        dp[sr] = col;
        for (auto it : adj[sr]) {
            if (dp[it] == -1) {
                if (dfs(it, adj, dp, !col) == false) {
                    return false;
                }
            } else if (dp[it] == col) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> dp(n, -1);
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) {
                if (!dfs(i, adj, dp, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// Time complexity: O(n+2m)
// space complexity: O(n) + O(n) (recursive stack space) = O(n)
