// Level: Easy
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int n = operations.size();
        int x=0;
        
        for(int i=0;i<n;i++)
        {
            if(operations[i][1]=='+')
            {
                x++;
            }
            else
            {
                x--;
            }
        }
        return x;
    }
};

// time complexity: O(n)
// space complexity: O(1)
