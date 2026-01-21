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
```cpp
```
-

### Postorder Traversal
```cpp

```
