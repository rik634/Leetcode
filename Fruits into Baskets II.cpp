// Level: easy
// Link: https://leetcode.com/problems/fruits-into-baskets-ii/description/
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();
        int placed=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<n;j++)
           {
               if(baskets[j]>=fruits[i] && vis[j]==false)
               {
                vis[j]=true;
                placed++;
                break;
               }
               else
               {
                continue;
               }
           }
        }
        return n-placed;
    }
};

// time complexity: O(n^2)
// space complexity: O(n)
