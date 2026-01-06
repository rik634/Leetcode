// level: Medium
// problem statement: 

// solution;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
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

        sort(res.begin(), res.end());
        return res;
    }
};
// Time complexity: O(V+E) ( for performing BFS on the graph (where V = number of vertices/nodes, E = number of edges) + O(NlogN) (for sorting the safeNodes array (where N is the number of safe nodes).) = 
// space complexity: O(N)
