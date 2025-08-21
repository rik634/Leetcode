// Level: Medium
struct Node{
    Node* links[26];
    bool flag=false;;

    bool containsKey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }

    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }

    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }

};
class Trie{
    private:
     Node* root;
    public:
   
    
    Trie(){
        root =new Node();
    }
    void insert(string word) {
           Node* node = root;
           for(int i=0;i<word.size();i++)
           {
               if(!node->containsKey(word[i]))
               {
                  node->put(word[i],new Node());
               }
              node = node->get(word[i]);
           }
           node->setEnd();
    }

    bool search(string word) {
        
        Node* node =root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

// Time complexity:
// 1. Insertion: O(N), where N is the length of the word being inserted.
// 2. Search: O(N), where N is the length of the word being searched.
// 3. StartsWith: O(N), where N is the length of the prefix being checked.

// Space complexity:
// - O(N * M), where N is the number of words in the Trie and M is the average length of the words.
// - The space complexity is due to the storage of nodes for each character in the Trie, which can grow with the number of words and their lengths.
