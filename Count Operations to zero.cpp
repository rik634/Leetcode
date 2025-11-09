// Level: easy
class Solution {
public:
    int countOperations(int num1, int num2) {
        
        int count=0;
        while(num1!=0 && num2!=0)
        {
            count+= (num1/num2);
            num1%=num2;
            swap(num1,num2);
        }
        return count;
    }
};

// used euclidean algorithm used mostly to find the GCD
// time complexity: O(log(max(num1,num2)))
// space complexity: O(1)
