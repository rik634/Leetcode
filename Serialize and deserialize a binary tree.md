## Problem statement
- Given a Binary Tree, design an algorithm to serialise and deserialise it. There is no restriction on how the serialisation and deserialization takes place.
- But it needs to be ensured that the serialised binary tree can be deserialized to the original tree structure. Serialisation is the process of translating a data structure or
- object state into a format that can be stored or transmitted (for example, across a computer network) and reconstructed later. The opposite operation, that is, extracting a data structure from stored information, is deserialization.

### Logic:
#### Serialisation:
- Check if the tree is empty: If the root is null, return an empty string.
- Initialise an empty string to store the serialised binary tree.
- Use a queue for level-order traversal: initialise a queue and enqueue the root.
- Within the level-order traversal loop:
  1. Dequeue a node from the queue.
  2. If the node is null, append "#" to the string.
  3. If the node is not null, append its data value along with a comma (",") as a delimiter. Enqueue its left and right children.
- Return the final string containing the serialised representation of the tree.

#### Deserialization
- Check if the serialised data is empty: If it is, return null.
- Tokenize the serialised data using a stringstream with comma as a delimiter.
- Read the first token and create the root node with this value.
- Use a queue for level-order traversal: initialise a queue and enqueue the root.
- Within the level-order traversal loop:
  1. Dequeue a node from the queue.
  2. Read the value for the left child.
  3. If it is "#", set the left child to null. Otherwise, create a new node and set it as the left child.
  4. Read the next value for the right child.
  5. If it is "#", set the right child to null. Otherwise, create a new node and set it as the right child.
  6. Enqueue the left and right children into the queue for further traversal.
- Return the reconstructed root of the tree.

### Solution
```cpp

```
