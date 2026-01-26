## Problem statement
- iven two Binary Trees, return if true if the two trees are identical, otherwise return false..
- Two trees are said to be identical if these three conditions are met for every pair of nodes :
  1. Value of a node in the first tree is equal to the value of the corresponding node in the second tree.
  2. Left subtree of this node is identical to the left subtree of the corresponding node.
  3. Right subtree of this node is identical to the right subtree of the corresponding node.

### Solution
```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool cLeft = isSameTree(p->left, q->left);
        if (cLeft == false) {
            return false;
        }
        bool cRight = isSameTree(p->right, q->right);
        if (cRight == false) {
            return false;
        }
        return true;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n/2)
