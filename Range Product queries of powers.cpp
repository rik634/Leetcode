// level: Medium
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> power;
        int res=n;
        int f=1;
        while(res>0)
        {
            if(res%2==1)
            {
                power.push_back(f);
            }
            res=res/2;
            f=f*2;
        }
        int m = power.size();
        int mod = 1000000007;
        vector<vector<int>> arr(m,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            f=1;
            for(int j=i;j<m;j++)
            {
                f = (long long) (f*power[j])%mod;
                arr[i][j]=f;
            }
        }
        vector<int> answer;
        for(auto it:queries)
        {
            answer.push_back(arr[it[0]][it[1]]);
        }
        return answer;
    }
};

// time complexity: O(logn^2 + q)
// space complexity: O(logn^2)
