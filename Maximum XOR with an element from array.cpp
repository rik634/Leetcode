// level: Hard
class Solution {
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
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        Trie trie;
        sort(nums.begin(),nums.end());
        int q = queries.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<q;i++)
        {
            v.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(v.begin(),v.end());
        vector<int> res(q,0);
        int index=0;
        for(int i=0;i<q;i++)
        {
            int m = v[i].first;
            int x = v[i].second.first;
            int ind = v[i].second.second;
            while(index<nums.size() && nums[index]<=m)
            {
                trie.insert(nums[index]);
                index++;
            }
            if(index==0)
            {
                res[ind]=-1;
            }
            else
            {
                res[ind]=trie.getMax(x);
            }
        }
        return res;
        
    }
};

// - Time complexity: O((N + Q) * 32) where N is the size of nums array and Q is the number of queries.
// - Space complexity: O(N * 32) for the Trie structure.

