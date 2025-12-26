// level:Medium
// problem statment: 

// brute force (prefix sum)
class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.length();
        int currCame=0;
        int totalCame=0;
        for(auto it:customers)
        {
            if(it=='Y')
            {
                totalCame++;
            }
        }
        int mn=INT_MAX;
        int ind=-1;
        for(int i=0;i<customers.length();i++)
        {
            int closedPenalty = (totalCame-currCame);
            int openPenalty = (i)-currCame;
            if(mn>(closedPenalty+openPenalty))
            {
                mn=(closedPenalty+openPenalty);
                ind=i;
            }
            currCame += (customers[i]=='Y') ? 1 : 0;
        }
        if(mn>(n-totalCame))
        {
            mn=(n-totalCame);
            ind=n;
        }
        return ind;

    }
};
// time complexity: O(n)
// space complexity:O(1)

// clean code
class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.length();
        int currCame = 0;

        for (auto it : customers) {
            if (it == 'Y') {
                currCame++;
            }
        }
        int mn = currCame;
        int ind = 0;
        for (int i = 0; i < customers.length(); i++) {
            if (customers[i] == 'Y') {
                currCame--;
            } else {
                currCame++;
            }
            if (mn > currCame) {
                mn = currCame;
                ind = i+1;
            }
        }

        return ind;
    }
};
// time complexity:O(n)
// space complexity:O(1)
