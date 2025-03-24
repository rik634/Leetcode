//level: medium
//link: https://leetcode.com/problems/count-days-without-meetings/description/
//solution
class Solution {
public:
    
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        int f=0;
        int l=0;
        for( auto it: meetings)
        {
            int s = it[0];
            int e = it[1];
            if(s>(l+1))
            {
                f+=(s-l-1);
            }
            l=max(l,e);
        }
        f+=(days-l);
        return f;
    }
};
