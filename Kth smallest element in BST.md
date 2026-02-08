## Problem statement
- Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

### Brute force
```cpp
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& res) {
        if (node != NULL) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }
    int kthSmallest(TreeNode* root, int k) {

        vector<int> res;
        inorder(root, res);
        return res[k - 1];
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n) + O(logn)= O(n)

### Logic
- Initialize an array to store the values of the nodes within the Binary Search Tree (BST).
- Execute an inorder traversal of the BST, adding each node's value to the array as you visit it. Use a counter to monitor the progress of the traversal, especially focusing on the Kth position. This eliminates the need for an additional data structure.
- To determine the Kth smallest element:
  - Observe the counter during the traversal. Upon reaching the value of K, record the current node's value as the Kth smallest.
- To determine the Kth largest element:
  - Conduct a reverse inorder traversal (right subtree first, then the current node, followed by the left subtree).
  - Increment a counter as each node is visited. When the counter reaches K, the current node's value is the Kth largest.
- Return the values corresponding to the Kth smallest and Kth largest elements, as determined by the above steps.

### Optimal
```cpp
class Solution {
public:
    void solve(TreeNode* root, int& cnt, int& ans, int k) {
        if (root == NULL || cnt >= k)
            return; // Stop if we already found the answer

        solve(root->left, cnt, ans, k);

        // Re-check after returning from left child
        if (cnt >= k)
            return;

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {

        int cnt = 0;
        int ans;
        solve(root, cnt, ans, k);
        return ans;
    }
};
```
- Time complexity: O(H+k) (H is the height of the tree. The algorithm must first travel down to the leftmost leaf (the smallest element), which takes O(H) time.k is the number of nodes visited as the recursion backtracks and moves right to find the target.)
- Space complexity: O(k) (In a balanced tree, the stack depth is O(log N).In a skewed tree (worst case), the stack depth can grow to O(N))
