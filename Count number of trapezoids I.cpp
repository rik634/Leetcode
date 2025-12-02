// level: Medium
class Solution {
public:
    const int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int,int> mp;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            mp[points[i][1]]++;
        }
        
        long long sum=0;
        long long count=0;
        for(auto it: mp)
        {
            long long edge = (long long)it.second*(it.second-1)/2;
            count+=(edge*sum);
            sum+=edge;
        }
       
       
        return count%MOD;

    }
};
// Time complexity: O(n)
// space complexity: O(n)
