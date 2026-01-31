### Problem statement
-  Given a Complete Binary Tree, count and return the number of nodes in the given tree.
-  A Complete Binary Tree is a binary tree in which all levels are completely filled, except possibly for the last level, and all nodes are as left as possible.

### Brute force
```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        int count=0;
        q.push(root);
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            count++;
            if(p->left!=NULL)
            {
                q.push(p->left);
            }
            if(p->right!=NULL)
            {
                q.push(p->right);
            }
        }
        return count;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n) (queue)

### optimized
### Logic
- If the last level of a binary tree is perfectly filled, known as a perfect binary tree, the count of nodes can be determined by the formula: 2h-1, where h is the height.
- To check if the last level of the Binary Tree is filled or not we can compare the left and right heights of the tree.
- If the left height equals right height, it indicates that the last level is completely filled.If the left height does not equal right height, the last level is not completely filled.
- In the case where left height and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree and in the right subtree , and then return the total count as 1 + leftNodes + rightNodes.
- If the height of the left subtree is equal to the height of the right subtree, we can directly calculate using the 2h-1 formula.
  1. Base Case: If the given node is null, we return 0 as there are no nodes to count.
  2. Recursive Calls: Recursively find the left height and right height of the Binary Tree.
  3. Comparison: If the left height is equal to the right height, it implies that the tree’s last level is completely filled. Return the count of nodes using the formula: return (1 << lh) - 1, where << represents the left shift operator and represents the power of 2.
- If the left height is not equal to the right height, it implies that the tree’s last level is not completely filled. Recursively call the function on the left and right subtree and return the final number of nodes as 1 + countNodes(root->left) + countNodes(root->right)
- Implement the find left height and right height functions:
  1. Start with the variable height set to 0.
  2. Use a while loop to traverse the left/right side of the tree incrementing the height until reaching a leaf node.
  3. Return the calculated height.

```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }
        int lh = 0, rh = 0;
        TreeNode* temp = root;
        while (temp != NULL) {
            lh++;
            temp = temp->left;
        }
        temp = root;
        while (temp != NULL) {
            rh++;
            temp = temp->right;
        }
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
```
- Time Complexity: O(log N * log N) where N is the number of nodes in the Binary Tree. The calculation of leftHeight and rightHeight takes O(log N) time.
  In the worst case, when encountering the second case (leftHeight != rightHeight), the recursive calls are made at most log N times (the height of the tree) Therefore, the total time complexity is O(log N * log N).
- Space Complexity : O(H) ~ O(N) where N is the number of nodes in the Binary Tree. The space complexity is determined by the maximum depth of the recursion stack, w
