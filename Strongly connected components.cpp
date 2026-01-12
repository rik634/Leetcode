// Level: Medium
// problem statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph..

// Kosaraju's Algorithm/ Method (topo sort, rev edges, reverse DFS)
//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st)
    {
        vis[node]=true;
        for(auto it:adj[node])
        {
            if(vis[it]==false)
            {
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    void revDfs(int node, vector<int> revAdj[], vector<bool>& vis)
    {
        vis[node]=true;
        for(auto it: revAdj[node])
        {
            if(vis[it]==false)
            {
                revDfs(it,revAdj,vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool> vis(n,false);
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int> revAdj[n];
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
            for(auto it:adj[i])
            {
                revAdj[it].push_back(i);
            }
        }
        
        int count=0;
        while(!st.empty())
        {
            int p = st.top();
            st.pop();
            if(vis[p]==false)
            {
                count++;
                revDfs(p,revAdj,vis);
            }
        }
        return count;
    }
};
// Time complexity: O(n+m) + O(n+m) + O(n+m) = O(n+m)
// Space complexity: O(n+m) (revAdj) + O(n) (vis) + O(n) (stack) = O(n+m)

// tarjan's Algorithm
//Position this line where user code will be pasted.
class Solution {
  public:
    int time=0;
    void dfs(int u, vector<vector<int>>& adj, vector<int>& low, vector<int>& disc, stack<int>& st, vector<bool>& onStack, vector<vector<int>>& scc)
    {
        time++;
        disc[u]=time;
        low[u]=time;
        st.push(u);
        onStack[u]=true;
        for(auto v: adj[u])
        {
            if(disc[v]==-1) // not visites
            {
                dfs(v,adj,low,disc,st,onStack,scc);
                low[u]=min(low[u],low[v]);
            }
            else if(onStack[v]==true) // there is a back edge/ cycle
            {
                low[u]=min(low[u],disc[v]);
            }
        }
        if(low[u]==disc[u])
        {
            vector<int> temp;
            while(true){
                int node = st.top();
                st.pop();
                onStack[node]=false;
                temp.push_back(node);
                if(node==u)
                {
                    break;
                }
            }
            scc.push_back(temp);
        }
    }
    int tarjan(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<vector<int>> scc;
        stack<int> st;
        vector<bool> onStack(n,false);
        vector<int> low(n,-1),disc(n,-1);
        
        for(int i=0;i<n;i++)
        {
            // not visited
            if(disc[i]==-1)
            {
                dfs(i,adj,low,disc,st,onStack,scc);
            }
        }
        return scc.size();
    }
};
// Time complexity: O(V+E) Each node and edge is visited exactly once.
// space complexity: O(V) (stack)
