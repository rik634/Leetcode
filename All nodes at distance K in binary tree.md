## Problem statement
- Given the root of a binary tree, the value of a target node target, and an integer k. Return an array of the values of all nodes that have a distance k from the target node. The answer can be returned in any order (N represents null).

### Logic:
- To find all nodes at a specific distance K from a given target node, we must be able to move both downward (to children) and upward (to parent). Since the binary tree doesn’t store parent links, we simulate this by converting the tree into an undirected graph. This allows traversal in all directions: left, right, and parent.
- Once we treat the tree as a graph, we perform a standard Breadth-First Search (BFS) starting from the target node and collect all nodes that are exactly K steps away.
  
  1. Build the Parent Map:
     - Traverse the entire binary tree using either BFS or DFS and map each node to its parent node. This step effectively adds upward connectivity to the tree, allowing access to parent nodes during traversal.
       1. Create a parentMap where each key is a child node and its value is the corresponding parent node.
       2. This transforms the binary tree into an undirected structure where each node can move left, right, or up.
  2. Perform BFS from the Target Node:
     - Begin a level-order (BFS) traversal from the target node to explore all nodes at increasing distances.
     - Initialize a queue with the target node and a set to track visited nodes.
     - For each node at the current BFS level:
       1. Visit the left child if it exists and hasn't been visited.
       2. Visit the right child if it exists and hasn't been visited.
       3. Visit the parent (from the parentMap) if it exists and hasn't been visited.
     - Repeat the process level by level until distance K is reached.
  3. Store the Result: When the BFS reaches distance K, all nodes remaining in the queue are exactly K edges away from the target node.
     - Store the values of these nodes in a result vector and return
    
### Solution:
```cpp
class Solution {
public:
    void mapParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (node == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->left != NULL) {
                q.push(p->left);
                mp[p->left] = p;
            }
            if (p->right != NULL) {
                q.push(p->right);
                mp[p->right] = p;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> mp;
        mapParent(root, mp);
        unordered_set<int> st;
        queue<TreeNode*> q;
        q.push(target);
        int count = 0;
        st.insert(target->val);
        while (!q.empty() && count != k) {
            int size = q.size();
            count++;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                if (p->left != NULL && st.find(p->left->val) == st.end()) {
                    q.push(p->left);
                    st.insert(p->left->val);
                }
                if (p->right != NULL && st.find(p->right->val) == st.end()) {
                    q.push(p->right);
                    st.insert(p->right->val);
                }
                if (mp.find(p) != mp.end() && st.find(mp[p]->val) == st.end()) {
                    q.push(mp[p]);
                    st.insert(mp[p]->val);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
```
- Time Complexity: O(N) ,We visit each node exactly once when building the parent map using BFS ,O(N). We again visit each node at most once during the second BFS traversal from the target, O(N).
    - Hence, the total time complexity is O(N), where N is the number of nodes in the binary tree.
- Space Complexity: O(N) , The parent map stores one entry per node,O(N). The queue and visited set used in BFS also take up to O(N) space in the worst case. Therefore, the total space complexity is O(N).
