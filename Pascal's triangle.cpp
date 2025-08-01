// Level: Easy

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> arr;
        arr.push_back({1});
        if(numRows==1)
        {
            return arr;
        }
        arr.push_back({1,1});
        if(numRows==2)
        {
            return arr;
        }
        for(int i=3;i<=numRows;i++)
        {
            vector<int> res(i,0);
            res[0]=1;
            res[i-1]=1;
            for(int j=1;j<(i-1);j++)
            {
                res[j]=arr[i-2][j]+arr[i-2][j-1];
            }
            arr.push_back(res);
            
        }
        return arr;
   }
};
// time complexity: O(n^2)
// space complexity: O(n*n)
