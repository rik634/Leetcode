// Level: medium
// brute force
int countDistinctSubstring(string s) {
    // Your code here
    unordered_set<string> sp;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        string str="";
        for(int j=i;j<n;j++)
        {
            str+=s[j];
            sp.insert(str);
        }
    }
    return sp.size()+1;
}
// - Time complexity: O(N^2)
//   - Space complexity: O(N^3) (in worst case, all substrings are distinct) 

// optimal
struct Node{
    Node* links[26] = {NULL}; // Initialize links to NULL
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node* root = new Node();
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        Node* node = root;
        for (int j = i; j < s.length(); j++) {
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}

// - Time complexity: O(N^2)
// - Space complexity: O(N^2) (in worst case, all substrings are distinct)
