## Problem statement
- Given a Binary Tree, return its Top View. The Top View of a Binary Tree is the set of nodes visible when we see the tree from the top.

### Solution
```cpp
class Solution {
public:
    // Function to return the top view of the binary tree
    vector<int> topView(Node* root) {
        // Create a vector to store the final answer
        vector<int> ans;

        // If the tree is empty, return an empty result
        if (root == NULL) {
            return ans;
        }

        // Create a map to store vertical level -> node value (only first encountered)
        map<int, int> mpp;

        // Create a queue for BFS that stores {node, vertical_level}
        queue<pair<Node*, int>> q;

        // Push the root node with vertical level 0
        q.push({root, 0});

        // Start BFS traversal
        while (!q.empty()) {
            // Extract the front element of the queue
            auto it = q.front();
            q.pop();

            // Get the node and its vertical position
            Node* node = it.first;
            int line = it.second;

            // If this vertical position is being visited for the first time, store it
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            // If there is a left child, push it with vertical level - 1
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // If there is a right child, push it with vertical level + 1
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Traverse the map and store values in the answer vector
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        // Return the result
        return ans;
    }
};
```
- Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the BFS traversal.

- Space Complexity: O(N/2 + N/2) where N represents the number of nodes in the Binary Tree. The main space consuming data structure is the queue used for BFS traversal.
    It acquires space proportional to the number of nodes in the level it is exploring hence in the worst case of a balanced binary tree, the queue will have at most N/2 nodes which is the maximum width.Additionally, the map is used to store the top view nodes based on their vertical positions.
    Hence its complexity will also be proportional to the greatest width level. In the worst case, it may have N/2 entries as well.
