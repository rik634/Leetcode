## Problem statement
- Given a Binary Tree, determine the maximum sum achievable along any path within the tree. A path in a binary tree is defined as a sequence of nodes where each pair of adjacent nodes is connected by an edge.
- Nodes can only appear once in the sequence, and the path is not required to start from the root. Identify and compute the maximum sum possible along any path within the given binary tree.

### Logic:
- We can solve the maximum path sum problem using recursively traversing the tree and treating each node as a possible turning point. At every node, we calculate two things:
   1. The maximum path sum that passes through the current node (left + right + node value). This is used to update our global maximum.
   2. The maximum path sum from the current node down one side (either left or right), which we return to the parent call.
- If a node is null, we return 0 since it doesn’t contribute to the path. This way, we explore all possible paths and keep track of the highest one found.
### Solution
```cpp
class Solution {
public:
    int checkSum(TreeNode* node, int& mxSum) {
     // Base case: null nodes contribute 0 to the path
        if (node == NULL) {
            return 0;
        }
       // Recursive call: find the max contribution from left and right subtrees
        // We use max(0, ...) to "prune" any branch that returns a negative sum
        int lSum = max(0, checkSum(node->left, mxSum));
        int rSum = max(0, checkSum(node->right, mxSum));

       // 1. "SPLIT" CASE: Check if the path through this node (left + right + node)
        // is the best path we've seen across the entire tree.
        mxSum = max(mxSum, lSum + rSum + node->val);
        return node->val + max(lSum, rSum);
    }
    int maxPathSum(TreeNode* root) {

        int mxSum = INT_MIN;
        checkSum(root, mxSum);
        return mxSum;
    }
};
```
- Time Complexity: O(N), each node is processed once in DFS Traversal.
- Space Complexity: O(H), auxiliary stack space, where H is height of Binary Tree.
