## Problem statemnt
- Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
- According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

### Logic
- Start by checking if the current root node is null or matches one of the target nodes (x or y). If the root is null or matches either target node, return the root, as it could be the LCA or simply indicate the end of the search path.
- Perform a recursive search in the left subtree to find nodes x and y by calling the LCA function on the left child of the current root.
- Similarly, perform a recursive search in the right subtree by calling the LCA function on the right child of the current root.
- After completing the recursive searches, analyze the results of both subtree searches:
   1. If both recursive calls return non-null values, it means one target node was found in each subtree. In this case, the current root node must be the LCA, as it is the common ancestor of both nodes.
   2. If only one of the subtree searches returns a non-null result, it implies both target nodes are located within the same subtree. Return the non-null result, which represents the LCA found in that subtree.

### Solution
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if (l != NULL && r != NULL) {
            return root;
        }
        if (l != NULL) {
            return l;
        }
        return r;
    }
};
```
- Time Complexity: O(N), where N is the number of nodes in the binary tree. In the worst case, we may need to traverse all nodes to find the LCA.
- Space Complexity: O(H), where H is the height of the binary tree. This is due to the recursive stack space used during the traversal. In the worst case, for a skewed tree, H can be equal to N, but for a balanced tree, H will be log(N).
