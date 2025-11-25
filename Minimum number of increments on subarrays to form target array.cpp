// level: Hard
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int n = target.size();
        int res=target[0];
        for(int i=1;i<n;i++)
        {
            if((target[i]-target[i-1])>0)
            {
                res+=(target[i]-target[i-1]);
            }
        }
        return res;
    }
};
// Time complexity: O(n)
// space complexity: O(1)
