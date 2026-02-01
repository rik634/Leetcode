## Problem statement
- You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
- Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

### Logic

### Recursive approach
```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==NULL)
        {
            return new TreeNode(val);
        }
        if(root->val>val)
        {
            root->left = insertIntoBST(root->left,val);
        }
        else
        {
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};
```
- Time complexity: O(logN) (H=logN)
- Space complexity: O(logN) (recursive stack space)

### Iterative approach
```cpp
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* temp = new TreeNode(val);
        if (root == NULL) {
            return temp;
        }
        TreeNode* curr = root;
        // Find the node who is going to
        // have the new node as its child
        while (curr != NULL) {
            if (curr->val > val && curr->left != NULL) {
                curr = curr->left;
            } else if (curr->val < val && curr->right != NULL) {
                curr = curr->right;
            } else {
                break;
            }
        }
        // If key is smaller, make it left
        // child, else right child
        if (curr->val < val) {
            curr->right = temp;
        } else {
            curr->left = temp;
        }
        return root;
    }
};
```
- Time complexity: O(logN) (H=logN, height of tree)
- Space complexity: O(1)
  
