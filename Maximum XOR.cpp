// Level: hard
struct Node{
    Node* links[2];
    bool containsKey(int bit)
    {
        return links[bit]!=NULL;
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node* node)
    {
        links[bit]=node;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    public:
    void insert(int num)
    {
        Node* node =root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i) &1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    public:
    int getMax(int num)
    {
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit))
            {
                maxNum = maxNum | (1<<i);
                node = node -> get(1-bit);
            }
            else
            {
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   
    Trie trie;
    for(auto it:arr1)
    {
        trie.insert(it);
    }
    int mx=0;
    for(auto it:arr2)
    {
        mx=max(mx,trie.getMax(it));
    }
    return mx;
}

// - Time Complexity: O(32*N + 32*M) where N is the length of the input array.
//   1. Insertion: The time complexity of inserting each number into the Trie is O(32) as each number is composed of 32 bits in the Binary Representation. This operation is performed for each of the N numbers in the first array.
//   2. Finding Maximum XOR Operation: To find the maximum XOR value for each number, we iterate through its 32 bits performing constant-time operations for each bit. This is performed for all M numbers in the second array hence this operation accounts for the second time complexity of O(32*N).
// - Space Complexity: O(32N) where N is the length of the input array. This algorithm has a linear space complexity with respect to the size of the input array and each number takes up space proportional to 32 which is the size in Binary Representation.
