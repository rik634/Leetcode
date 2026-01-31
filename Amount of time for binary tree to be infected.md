## Problem statement
- Given a target node data and a root of binary tree. If the target is set on fire, determine the shortest amount of time needed to burn the entire binary tree.
- It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


### Parent map approach
```cpp
class Solution {
public:
    TreeNode* mpParent(TreeNode* node, unordered_map<TreeNode*,TreeNode*>& mp,int& start)
    {
        if(node==NULL)
        {
            return NULL;
        }
        queue<TreeNode*> q;
        TreeNode* startNode;
        q.push(node);
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p->val==start)
            {
                startNode=p;
            }
            if(p->left!=NULL)
            {
                q.push(p->left);
                mp[p->left]=p;
            }
            if(p->right!=NULL)
            {
                q.push(p->right);
                mp[p->right]=p;
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* sNode = mpParent(root,mp,start);
        queue<TreeNode*> q;
        unordered_set<int> st;
        st.insert(start);
        q.push(sNode);
        int time=-1;
        while(!q.empty())
        {
            int size = q.size();
            time++;
            for(int i=0;i<size;i++)
            {
                auto p = q.front();
                q.pop();
                if(p->left!=NULL && st.find(p->left->val)==st.end())
                {
                    q.push(p->left);
                    st.insert(p->left->val);
                }
                if(p->right!=NULL && st.find(p->right->val)==st.end())
                {
                    q.push(p->right);
                    st.insert(p->right->val);
                }
                if(mp.find(p)!=mp.end() && st.find(mp[p]->val)==st.end())
                {
                    q.push(mp[p]);
                    st.insert(mp[p]->val);
                }
            }
        }
        return time;

    }
};
```
- Time complexity: O(N) (find parent) + O(N) (BFS)
- Space complexity: O(N) (queue, map)

### create undirected graph approach
```cpp
class Solution {
public:
    void createMap(TreeNode* node,unordered_map<int,vector<int>>&mp){

        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p->left!=NULL)
            {
                q.push(p->left);
                mp[p->val].push_back(p->left->val);
                mp[p->left->val].push_back(p->val);
            }
            if(p->right!=NULL)
            {
                q.push(p->right);
                mp[p->val].push_back(p->right->val);
                mp[p->right->val].push_back(p->val);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<int,vector<int>> mp;
        createMap(root,mp);  
        unordered_set<int> st;
        st.insert(start);
        int time=-1;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int size = q.size();
            time++;
            for(int i=0;i<size;i++)
            {
                auto p = q.front();
                q.pop();
                for(auto v:mp[p])
                {
                    if(st.find(v)==st.end())
                    {
                        st.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        return time;
    }
};
```
- Time complexity: O(N)
- Space complexity: O(N)
- here, we are using vector rather than unordered set, because, each vector will have max of 4 entries, which saves hashing overghead, which we get if we use Unordered set

### Most optimized (prefered by interviewer)

### Logic:
- It calculates two different things at once. If the start node is in the subtree, it uses the sum of the heights to find the "infection" distance. If not, it just returns the height normally.
- The Two Modes of the Return Value
  1. Positive Value (Height): If the subtree does not contain the start node, the function returns the standard height (distance to the deepest leaf).
  2. Negative Value (Distance): If the subtree does contain the start node, it returns the distance to that node as a negative number (e.g., -1 means the child is the start, -2 means the grandchild is the start).
- How the Calculation Works
  - When a node receives a negative value from one child and a positive value from the other, it means the "infection" is coming up from one side and needs to go down the other.
    1. Let’s say the Left child returns -3 (The start node is 3 edges deep on the left).
    2. Let’s say the Right child returns 5 (The deepest leaf on the right is 5 edges deep).
    3. The total time to reach that deepest leaf is abs(-3) + 5 = 8
- Why min(L, R) - 1?
  - Since one value is negative (the distance) and one is positive (the height), min(L, R) will always pick the negative one.
  - Subtracting 1 from a negative number (e.g., $-2 - 1 = -3$) effectively increases the "distance" count as we move up to the parent.
  - If the start node is in the left subtree, L will be negative (e.g., -2) and R will be positive (e.g., 3).
      min(-2, 3) = -2 By picking the minimum, we are essentially saying: "Ignore the height of the healthy branch for the return value; focus on the distance to the infected node."
  - As the recursion "pops" back up to the parent, we are moving one edge further away from the start node.
    1. If a child tells the parent: "The infection is 2 steps away from me" (returns -2).
    2. The parent is now 3 steps away from that infection.
    3. The parent calculates: -2 - 1 = -3 and passes that to its parent.
   
```cpp
class Solution {
public:
    int height(TreeNode* node, int& start, int& time) {
        int d = 0;
        if (node == NULL) {
            return d;
        }
        int left = height(node->left, start, time);
        int right = height(node->right, start, time);

        // Case 1: Current node is the start node
        if (node->val == start) {
            time = max(left, right);
            d = -1;
        } // Case 2: Start node not found yet, return standard height
        else if (left >= 0 && right >= 0) {
            d = max(left, right) + 1;
        } /// Case 3: Start node is in one of the subtrees (L or R is negative)
        else {
            // Distance logic: |L| + |R| gives the path length from start
            // through current node
            int dist = abs(left) + abs(right);
            time = max(time, dist);
            // Continue passing the negative distance up
            d = min(left, right) - 1;
        }
        return d;
    }
    int amountOfTime(TreeNode* root, int start) {

        int time = 0;
        height(root, start, time);
        return time;
    }
};
```
- Time Complexoty: O(N) (One single post-order traversal).
- Space Complexity: O(H) (No extra maps, just the recursion stack).
