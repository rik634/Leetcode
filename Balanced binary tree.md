## Problem statement
- Given a Binary Tree, return true if it is a Balanced Binary Tree else return false. A Binary Tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1..


### Brute force
```cpp
class Solution {
public:
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int lh = height(node->left);
        int rh = height(node->right);
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return abs(lh - rh) <= 1 && isBalanced(root->left) &&
               isBalanced(root->right);
    }
};
```
- Time Complexity: O(N2), where N is the number of nodes in the binary tree. For each node, we calculate the height of its left and right subtrees, and height calculation takes O(N) in the worst case, leading to an overall O(N × N) = O(N²).
- Space Complexity: O(H), where H is the height of the tree. This space is used by the recursive call stack of the getHeight function. In the worst case (skewed tree), H = N, and in the best case (balanced tree), H = log N. No additional data structures are used, so auxiliary space remains constant.

### Optimized
- The O(N²) time complexity of the previous approach can be optimized by checking the balance condition while traversing the tree in a bottom-up manner. Instead of repeatedly calculating the height at each node, we compute subtree heights during postorder traversal and evaluate the balance condition at the same time.
- This avoids redundant height calculations and allows early detection of unbalanced nodes, thereby preventing unnecessary recursive calls. Postorder traversal helps ensure that we already have the height information of both subtrees when we assess the balance condition at any node.
  1. Traverse the Binary Tree in post-order using recursion: visit the left subtree, then the right subtree, and finally the current node.
  2. At each node, compute the height of its left and right subtrees using recursive calls.
  3. Check the absolute difference between the heights of the left and right subtrees. If the difference is greater than 1, or if either subtree is already unbalanced (returns -1), return -1 to indicate an unbalanced state.
  4. If the subtree is balanced, return the height of the current node as max(left height, right height) + 1.
  5. Continue the traversal until all nodes are visited. If no -1 is returned, the tree is balanced.

```cpp
class Solution {
public:
    int height(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        int lh = height(node->left);
        if (lh == -1) {
            return -1;
        }

        int rh = height(node->right);
        if (rh == -1) {
            return -1;
        }
        if (abs(rh - lh) > 1) {
            return -1;
        }

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) { return height(root) != -1; }
};
```
- Time Complexity: O(N), where N is the number of nodes in the Binary Tree. Each node is visited exactly once during the postorder traversal.
- Space Complexity: O(1), since no extra data structures are used that grow with input size. However, O(H) auxiliary space is used by the recursion stack, where H is the height of the tree. In the best case (balanced tree), H = log₂N; in the worst case (skewed tree), H = N.
