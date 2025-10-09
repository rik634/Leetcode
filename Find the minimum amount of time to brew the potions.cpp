// Level: Medium
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        
       
        int n = skill.size();
        int m = mana.size();
         vector<long long > times(n,0);
        
        for(int i=0;i<m;i++)
        {
           long long curr=0;
            for(int j=0;j<n;j++)
            {
                curr=max(curr,times[j])+skill[j]*mana[i];
            }
            times[n-1]=curr;
            for(int j=n-2;j>=0;j--)
            {
                times[j]=times[j+1]-skill[j+1]*mana[i];
            }
        }
        return times[n-1];
    }
};
// time complexity: O(m*n)
// space complexity: O(n)
