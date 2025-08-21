// Level: Medium
#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int cntEndsWith=0;
    int cntPrefix=0;

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
    void increasePrefix()
    {
        cntPrefix++;
    }
    void increaseEndWith()
    {
        cntEndsWith++;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    void reduceEndsWith()
    {
        cntEndsWith--;
    }
    int getEndsWith()
    {
        return cntEndsWith;
    }
    int getPrefix()
    {
        return cntPrefix;
    }

};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEndsWith();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->reduceEndsWith();
    }
};

// - Time complexity: O(N), (for each operation where N is the length of the word).
// - Space complexity: O(N), where N is the number of unique characters in the Trie.
