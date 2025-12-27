// level: easy
// problem statement: Given a linked list and an integer value val, insert a new node with that value at the beginning (before the head) of the list and return the updated linked list.

class Node{
 public:
      int data;
      Node* next;
      Node(Node* node, int data){
        next=node;
        data=data;
      }
      Node(int data){
        data=data;
      }
};
class Solution{
    public:
    Node* insertNode(Node* head,int val){

          Node* newNode = new Node(val);
           newNode->next=head;
          return newNode;
    }
};

// time complexity:O(1)
// space complexity:O(1)
