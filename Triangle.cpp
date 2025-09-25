// Level: Mediuim
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> v;
        v.push_back({triangle[0][0]});
        if(n==1)
        {
            return triangle[0][0];
        }
        for(int i=1;i<n;i++)
        {
            vector<int> res(i+1,INT_MAX);
            
            for(int j=0;j<res.size();j++)
            {
               
                if(j<res.size()-1)
                {
                    res[j]=min(res[j],triangle[i][j]+v[i-1][j]);
                }
                
                if((j-1)>=0)
                {
                    res[j]=min(res[j],triangle[i][j]+v[i-1][j-1]);
                }
            }
            v.push_back(res);
        }
        int mn=INT_MAX;
        for(auto it:v[n-1])
        {
            mn=min(mn,it);
        }
        return mn;
    }
};
// time complexity: O(n^2)
// space complexity: O(n^2)

// space optimized
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> prev;
        prev.push_back(triangle[0][0]);
        if(n==1)
        {
            return triangle[0][0];
        }
        for(int i=1;i<n;i++)
        {
            vector<int> res(i+1,INT_MAX);
            
            for(int j=0;j<res.size();j++)
            {
               
                if(j<res.size()-1)
                {
                    res[j]=min(res[j],triangle[i][j]+prev[j]);
                }
                
                if((j-1)>=0)
                {
                    res[j]=min(res[j],triangle[i][j]+prev[j-1]);
                }
            }
            prev=res;
        }
        int mn=INT_MAX;
        for(auto it:prev)
        {
            mn=min(mn,it);
        }
        return mn;
    }
};
// time complexity: O(n^2)
// space complexity: O(n)
