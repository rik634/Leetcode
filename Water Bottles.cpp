// level: Easy
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int n = numBottles;
        int count=n;
        while(n>=numExchange)
        {
            int rem = n % numExchange;
           
            int d = n/numExchange;
             count+=d;
            n = rem+d;
        }
        return count;
    }
};

// Time complexity: O(logn) (base numExchange)
// space complexity: O(1)
