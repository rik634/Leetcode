// level: hard
class Solution {
public:
    long long ops(int num)
    {
        long long op=1;
        long long i=1;
        long long res=0;
        while(i<=num)
        {
            long long end = min(2*i-1,(long long)num);
            long long totalNumbersInRange = end-i+1;
            // for each number, the number of operations required is same, which is denoted by op.
            res+= ((op+1)/2)* (totalNumbersInRange);
            i*=2;
            op++;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        
        long long count=0;
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r = queries[i][1];
            count+= (ops(r)-ops(l-1)+1)/2;
        }
        return count;
    }
};
// Let n be the number of queries, and let R be the maximum value of r across all intervals.
// time complexity: O(nlogR)
// space complexity: O(1)
