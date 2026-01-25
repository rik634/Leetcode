## Binary tree

### Representation in C++
```cpp
class Node {
public:
    int data;      // Stores the value of the node
    Node* left;    // Pointer to the left child node
    Node* right;   // Pointer to the right child node

    // Constructor to initialize a node with a given key
    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};
```

### Representation in Java
```java
class Node { 
    int data;       // Stores the value of the node
    Node left;      // Reference to the left child node
    Node right;     // Reference to the right child node

    // Constructor to initialize a node with a given key
    public Node(int key) {
        data = key;     
        left = null;    
        right = null;   
    }
}

// Class containing the logic for Binary Tree creation
class Solution {
    public Node createBinaryTree() {
        // Creates the root node with key value 1
        Node root = new Node(1);       

        // Creates a left child node for the root with key value 2
        root.left = new Node(2);       

        // Creates a right child node for the root with key value 3
        root.right = new Node(3);      

        // Creates a left child node for the right child of root with key value 5
        root.right.left = new Node(5); 

        return root;
    }
}
```

### Traversal 
- Binary traversal technque:
  1. DFS (Depth first search)
     a. Preorder traversal
     b. Inorder traversal
     c. Postorder traversal
  3. BFS (breadth first search)
     a. Level Order Traversal

### Preorder Traversal:
```cpp
class Solution {
public:
    void preorder(TreeNode* node, vector<int>& res) {
        if (node != NULL) {
            res.push_back(node->val);
            preorder(node->left, res);
            preorder(node->right, res);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if (root == NULL) {
            return {};
        }
        preorder(root, res);
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n) (recursive stack space) + O(n) (res) = O(n)

- Iterative approach
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if (root == NULL) {
            return {};
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right != NULL) {
                st.push(node->right);
            }
            if (node->left != NULL) {
                st.push(node->left);
            }
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(h)


### Inorder Traversal
- recursive approach
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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        inorder(root, res);
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n) (stack space + vector)

- Iterative approach
- Logic:
  1. Initialize an empty stack and set the current node to the root of the binary tree.
  2. Enter a loop that continues as long as there are nodes in the stack or the current node is not null.
  3. If the current node is not null, push it onto the stack and move to its left child. Continue this process until a node with no left child is reached.
  4. Once a null node is encountered, pop the top node from the stack, process it (e.g., add its value to the result array), and move to its right child.
  5. Repeat this process of pushing and popping nodes, alternating between moving left and right, until the stack is empty and the current node is null.
  6. At the end of the process, return the result array, which will contain the inorder traversal of the binary tree.

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) {
                    break;
                }
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};
```
- Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
- Space Complexity: O(h), where h is the height of the binary tree. This is the space required for the stack to store the nodes during traversal.

### Postorder Traversal
- Recursive approach
```cpp
class Solution {
public:
    void f(TreeNode* node, vector<int> & res)
    {
        if(node!=NULL)
        {
            f(node->left,res);
            f(node->right,res);
            res.push_back(node->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        f(root,res);
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n) (recursive stack space+vector)

- Iterative approach (using one stack)
```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if (root == NULL) {
            return {};
        }
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->left != NULL) {
                st.push(node->left);
            }
            if (node->right != NULL) {
                st.push(node->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
- Time complexity: o(N)
- Space complexity: O(h), h=height of tree for stack

- Iterative approach (using 2 stacks)
```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if (root == NULL) {
            return {};
        }
        stack<TreeNode*> st,st1;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            st1.push(node);
            if (node->left != NULL) {
                st.push(node->left);
            }
            if (node->right != NULL) {
                st.push(node->right);
            }
        }
        while(!st1.empty())
        {
            res.push_back(st1.top()->val);
            st1.pop();
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)+ O(h)

### Level order Traversal
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) {
            return {};
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                temp.push_back(p->val);
                if (p->left != NULL) {
                    q.push(p->left);
                }
                if (p->right != NULL) {
                    q.push(p->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
```
- Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once during the level-order traversal.
- Space Complexity: O(N), where N is the number of nodes in the binary tree. The space is used by the queue to store nodes at each level, and in the worst case, it can hold all nodes at the last level.


### Preorder, Inorder, postorder in single traversal
```cpp
class Solution {
public:
    // Function to get the Preorder,
    // Inorder and Postorder traversal
    // Of Binary Tree in One traversal
    vector<vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store traversals
        vector<int> pre, in, post;

        // If the tree is empty,
        // return empty traversals
        if (root == NULL) {
            return {};
        }

        // Stack to maintain nodes
        // and their traversal state
        stack<pair<Node*, int>> st;

        // Start with the root node
        // and state 1 (preorder)
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            // this is part of pre
            if (it.second == 1) {
                // Store the node's data
                // in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2
                // (inorder) for this node
                it.second = 2;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push left child onto
                // the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data
                // in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3
                // (postorder) for this node
                it.second = 3;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push right child onto
                // the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else {
                // Store the node's data
                // in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};
```
- Time Complexity: O(3*N), we process each node thrice, once for every traversal.
- Space Complexity: O(4*N), extra space used for storing postorder, inorder, preorder traversal and stack.

### Height of binary tree
```cpp
class Solution {
public:
    int height(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
    int maxDepth(TreeNode* root) { return height(root); }
};
```
- Time Complexity: O(N), each node is processed once in Level Order Traversal.
- Space Complexity: O(N), in worst case, a maximum of N/2 nodes can be present in queue.

### Diameter of binary tree
- Brute force
```cpp
class Solution {
public:
    int height(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        int d = lh + rh;
        int dl = diameterOfBinaryTree(root->left);
        int dr = diameterOfBinaryTree(root->right);
        return max(d, max(dl, dr));
    }
};
```
- Time complexity: O(n*n)
- Space complexiy: O(1)

- Optimized
```cpp
class Solution {
public:
    int height(TreeNode* node, int& d)
    {
        if(node==NULL)
        {
            return 0;
        }
        int lh = height(node->left,d);
        int rh = height(node->right,d);
        d=max(d,lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d=0;
        height(root,d);
        return d;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)   
