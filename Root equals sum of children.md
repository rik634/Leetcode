## Problem statemnt
- You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
- Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

### Solution
```cpp
class Solution {
public:
    bool checkTree(TreeNode* root) {

        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        int sum = 0;
        if (root->left != NULL) {
            sum += root->left->val;
        }
        if (root->right != NULL) {
            sum += root->right->val;
        }

        return (sum == root->val) && checkTree(root->left) &&
               checkTree(root->right);
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n/2)

### Chnage the tree to follow the root sum children property
- Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. The Children Sum Property in a binary tree states that for every node, the sum of its children's values (if they exist) should be equal to the node's value. If a child is missing, it is considered as having a value of 0.
- Note:
  1. The node values can be increased by any positive integer any number of times, but decrementing any node value is not allowed.
  2. A value for a NULL node can be assumed as 0.
  3. We cannot change the structure of the given binary tree.

### Solution
```cpp
class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }

        // Compare the sum of children with
        // the current node's value and update
        if (child >= root->val) {
            root->val = child;
        } else {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }

        // Recursively call the function
        // on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the
        // values of the left and right
        // children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }

        // If either left or right child
        // exists, update the current node's
        // value with the total sum.
        if (root->left or root->right) {
            root->val = tot;
        }
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)
