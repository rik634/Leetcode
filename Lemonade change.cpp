// Level: easy
// Link: https://leetcode.com/problems/lemonade-change/description/
// Solution
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int five=0;
        int ten =0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
            else if(bills[i]==10)
            {
                if(five>0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(ten>0 && five>0)
                {
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else
                {
                    return false;
                }
            }

        }
        return true;
    }
};
// Time complexity: O(N)
// Space complexity: O(1)
