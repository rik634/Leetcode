// Level: Easy
class Solution {
public:
    int countTriples(int n) {
        
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                long long c = (long long)sqrt(i*i+j*j);
                if((c*c)==(i*i+j*j) && c<=n)
                {
                    count++;
                }

            }
        }
        return count;
    }
};
// Time complexity: O(n*n)
// Space complexity: O(1)
