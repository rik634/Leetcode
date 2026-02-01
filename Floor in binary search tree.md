## Problem statement
- Given a Binary Search Tree and a key, return the floor of the given key in the Binary Search Tree.
- Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key. If the floor node does not exist, return nullptr.

### Logic
- Traverses the tree, either finding the exact key or reaching the nodes that approach the given key’s value. During the traversal, at every node, if the key matches the node’s values, it directly assigns the node’s value as the floor and concludes the search.
- If the key is smaller than the current node’s value, the algorithm navigates to the left subtree to potentially find a smaller value and if the key is larger the algorithm updates the floor value with the current node’s values and explores the right subtree for potentially larger values.
  1. Initialise a variable floor to -1 to store the result initially.
  2. Traverse the Binary Search Tree starting from the root.
  3. If the key is equal to the current node’s value, assign it to floor and return.
  4. If the key is greater than the current node’s value, update floor with the current node’s value and move to the right subtree.
  5. If the key is smaller than the current node’s value, move to the left subtree.
  6. After traversal, return floor, which represents the largest value smaller than or equal to the key, or -1 if no such value exists.
 
### Solution
```cpp
class Solution {
public:
    // Function to find the floor of a key
    // in a Binary Search Tree (BST)
    int floorInBST(TreeNode* root, int key){
        // Initialize the floor variable
        int floor = -1;
        
        // Traverse the BST until root becomes null
        while(root){
            // If key is equal to current node value
            // then it is the floor
            if(root->val == key){
                floor = root->val;
                return floor;
            }
            
            // If key is greater than current node value
            // move right and update floor
            if(key > root->val){
                floor = root->val;
                root = root->right;
            }
            else{
                // If key is smaller, move left
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
};
```
- Time Complexity: O(log2N), where N is the number of nodes in the Binary Search Tree. The complexity is equivalent to the height of the tree.
- Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
