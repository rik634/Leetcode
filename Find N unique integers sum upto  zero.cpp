// Level : easy
class Solution {
public:
    vector<int> sumZero(int n) {
        
        if(n==1)
        {
            return {0};
        }
        vector<int> res;
        for(int i=1;i<=(n/2);i++)
        {
            res.push_back(i);
            res.push_back(-1*i);
        }
        if(n%2!=0)
        {
            res.push_back(0);
        }
        return res;
    }
};
// time complexity: O(n/2)
// space complexity: O(n)
