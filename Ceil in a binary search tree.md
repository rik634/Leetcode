## Problem statement
-  Given a Binary Search Tree and a key, return the ceiling of the given key in the Binary Search Tree.
- Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key. If the ceiling node does not exist, return nullptr.

### Logic:
- Traverse the tree recursively and move through it until it reaches the end or locates the key. During the traversal, at every node, if the key matches the node’s values, it directly assigns the node’s value as the ceiling and concludes the search.
- If the key is greater than the current node’s value, the algorithm navigates to the right subtree to potentially find a larger value and if the key is smaller the algorithm updates the ceil value with the current node’s values and explores the left subtree for potentially smaller values.
  1. Initialise a variable ceil to -1 to store the result initially.
  2. Traverse the Binary Search Tree starting from the root.
  3. If the key is equal to the current node’s value, assign it to ceil and return.
  4. If the key is smaller than the current node’s value, update ceil with the current node’s value and move to the left subtree.
  5. If the key is greater than the current node’s value, move to the right subtree.
  6. After traversal, return ceil, which represents the smallest value greater than or equal to the key, or -1 if no such value exists.
 
### Solution
```cpp
class Solution {
public:
    // Function to find the ceiling of
    // a key in a Binary Search Tree (BST)
    int findCeil(TreeNode* root, int key){
        // Initialize the variable
        // to store the ceiling value
        int ceil = -1; 
        
        // Traverse the BST until reaching
        // the end or finding the key
        while(root){
             // If the key is found, assign it
             // as the ceiling and return
            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
            
             // If the key is greater,
             // move to the right subtree
            if(key > root->val){
                root = root->right;
            }
            else{ 
                // If the key is smaller, update ceil
                // and move to the left subtree
                ceil = root->val;
                root = root->left;
            }
        }
         // Return the computed ceiling value
        return ceil;
    }
};
```
- Time Complexity: O(log2N), where N is the number of nodes in the Binary Search Tree. The complexity is equivalent to the height of the tree.
- Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
