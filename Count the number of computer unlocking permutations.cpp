// Level: Medium
class Solution {
public:
    const int MOD=1e9+7;
    int countPermutations(vector<int>& complexity) {
        
        int n = complexity.size();

        int mn=complexity[0];
        for(int i=1;i<n;i++)
        {
            if(mn>=complexity[i])
            {
               return 0;
            }
        }
       
        int f = 1;
        for(int i=1;i<n;i++)
        {
            f=(long long)f*i%MOD;;
        }
        return f;

    }
};
// Time complexity: O(n)
// space complexity: O(1)
