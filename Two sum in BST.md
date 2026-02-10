## Problem statement
- Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

### Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* node, vector<int>& nums)
    {
        if(node!=NULL)
        {
            inorder(node->left,nums);
            nums.push_back(node->val);
            inorder(node->right,nums);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> nums;
        inorder(root,nums);

        int n = nums.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int sum = nums[l]+nums[r];
            if(sum==k)
            {
                return true;
            }
            else if(sum<k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return false;
        
    }
};
```
- Time Complexity: O(N+N) where N is the number of nodes in the Binary Search Tree. To create the array that will store the inorder sequence, we have to traverse the entire BST, hence O(N) and to apply the two pointer approach and get the pair equal to sum again requires O(N) hence O(N+N) ~ O(2N) ~ O(N).
- Space Complexity : O(N)where N is the number of nodes in the BST, as we have to store all the nodes in an additional data structure array. The two pointer approach does not use any additional space hence the space complexity is O(N).

### Another appraoch
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
private:
    // A stack is used to keep track of nodes while traversing
    stack<TreeNode*> myStack;
    // This flag tells whether we are moving forward (inorder) or backward
    // (reverse inorder)
    bool reverse;

public:
    // Constructor initializes the iterator with the root node and traversal
    // direction
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        // Push all nodes on one side (left or right) into the stack
        pushAll(root);
    }

    // This function checks if there are more nodes left to visit
    bool hasNext() {
        // If the stack is not empty, there are still nodes left
        return !myStack.empty();
    }

    // This function returns the next node’s value in the chosen order
    int next() {
        // Get the node on top of the stack
        TreeNode* tmpNode = myStack.top();
        // Remove this node from the stack
        myStack.pop();

        // If we are not in reverse mode, we need to go right after visiting a
        // node
        if (!reverse) {
            pushAll(tmpNode->right);
        }
        // If we are in reverse mode, we need to go left after visiting a node
        else {
            pushAll(tmpNode->left);
        }

        // Return the value of the node that was just visited
        return tmpNode->val;
    }

private:
    // This helper function pushes all nodes from the current node down to the
    // left/right edge
    void pushAll(TreeNode* node) {
        // Keep going until we reach a null node
        while (node != nullptr) {
            // Push the node onto the stack
            myStack.push(node);
            // If reverse is true, move to the right child
            if (reverse) {
                node = node->right;
            }
            // Otherwise, move to the left child
            else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    // This class contains the solution logic to check if a target sum exists in
    // BST This function checks if two nodes in BST sum to k
    bool findTarget(TreeNode* root, int k) {
        // If tree is empty, return false immediately
        if (!root)
            return false;

        // Create two iterators: one for smallest-to-largest order, another for
        // largest-to-smallest
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        // Get first values from both ends
        int i = l.next();
        int j = r.next();

        // Loop until the two pointers meet
        while (i < j) {
            // If the two numbers add up to k, we found a pair
            if (i + j == k)
                return true;
            // If sum is too small, move left iterator forward
            else if (i + j < k)
                i = l.next();
            // If sum is too large, move right iterator backward
            else
                j = r.next();
        }

        // If no pair found, return false
        return false;
    }
};
```
- Time Complexity: O(N) where N is the number of nodes in the BST as we have to traverse all the nodes using the i and j pointers to find the pair with sum ‘k’.
- Space Complexity : O(H) where H is the height of the Binary Search Tree as the BSTIterator class uses a stack to store the nodes. At maximum the size of such a stack will be equal to the height of the Binary Tree.
