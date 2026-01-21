## Binary tree

### Representation
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
