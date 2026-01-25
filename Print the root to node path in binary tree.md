## problem statement



### Solution
```cpp
class Solution {
public:
    // Function to find the path from root to node with value x
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        // If current node is NULL, return false
        if (!root) {
            return false;
        }

        // Add current node's value to the path
        arr.push_back(root->val);

        // If current node's value is equal to x, return true
        if (root->val == x) {
            return true;
        }

        // Recursively search in left or right subtree
        if (getPath(root->left, arr, x) ||
            getPath(root->right, arr, x)) {
            return true;
        }

        // If not found, backtrack and remove current node
        arr.pop_back();
        return false;
    }

    // Function to get the path from root to node with value B
    vector<int> solve(TreeNode* A, int B) {
        // Vector to store the path
        vector<int> arr;

        // If root is NULL, return empty path
        if (A == NULL) {
            return arr;
        }

        // Call helper function to fill the path
        getPath(A, arr, B);

        // Return the resulting path
        return arr;
    }
};
```
- Time Complexity: O(N), where N is the number of nodes in the binary tree as each node of the binary tree is visited exactly once in the inorder traversal.
- Space Complexity: O(N), additional stack space used for recursion and space for storing the path.
