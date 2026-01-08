// level: Medium
// problem statement: 

// brute force (array)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        vector<bool> vis(n + 1, false);

        for (int i = 1; i <= n; i++) {
            int u = -1;
            for (int v = 1; v <= n; v++) {
                if (vis[v] == false && (u == -1 || dist[v] < dist[u])) {
                    u = v;
                }
            }
            if (dist[u] == INT_MAX) {
                break;
            }
            for (auto it : adj[u]) {
                int w = it.second;
                int v = it.first;
                if ((dist[u] + w) < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
            vis[u] = true;
        }
        int mx = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};
// Time complexity:O(V*V)
// space complexity: o(V+E)

// further optimize (using priority queue)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            st;
        dist[k] = 0;
        st.push({dist[k], k});
        while (!st.empty()) {
            int d = st.top().first;
            int u = st.top().second;
            st.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto it : adj[u]) {
                int w = it.second;
                int v = it.first;

                if ((dist[u] + w) < dist[v]) {

                    dist[v] = dist[u] + w;
                    st.push({dist[v], v});
                }
            }
        }
        int mx = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};
// Time complexity: O(ElogV)
// space complexity; O(V+E)


// optimized (using set)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;
        dist[k] = 0;
        st.insert({dist[k], k});
        while (!st.empty()) {
            int d = st.begin()->first;
            int u = st.begin()->second;
            st.erase(st.begin());
            for (auto it : adj[u]) {
                int w = it.second;
                int v = it.first;
                if ((dist[u] + w) < dist[v]) {
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = dist[u] + w;
                    st.insert({dist[v], v});
                }
            }
        }
        int mx = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            mx = max(mx, dist[i]);
        }
        return mx;
    }
};
// Time complexity: O(ElogV)
// space complexity: O(V+E)
