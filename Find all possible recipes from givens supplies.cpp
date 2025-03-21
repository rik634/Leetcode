//level:medium
//link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/
//solution
class Solution {
public:
    unordered_map<string,int> mp;
    vector<string> topo;
    unordered_set<string> s;
    void getTopoSort(int n,vector<vector<string>>& ingredients,vector<string>& recipes)
    {
        unordered_map<string,vector<string>> adj;
        vector<int> indegree(n,0);
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                string r = recipes[i];
                string ing = ingredients[i][j];
                if(s.find(ing)==s.end())
                {
                    adj[ing].push_back(r);
                    indegree[mp[r]]++;
                }
            
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            topo.push_back(recipes[p]);
            for(auto it:adj[recipes[p]])
            {
                indegree[mp[it]]--;
                if(indegree[mp[it]]==0)
                {
                    q.push(mp[it]);
                }
            }
        }
        
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        for(int i=0;i<supplies.size();i++)
        {
            s.insert(supplies[i]);
        }
        for(int i=0;i<n;i++)
        {
            mp.insert({recipes[i],i});
        }
        getTopoSort(n,ingredients, recipes);
        return topo;
    }
};
