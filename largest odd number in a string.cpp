// level: easy
// problem statement:  Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
//The number returned should not have leading zero's. But the given input string may have leading zero.

// brute force
class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.length();
        string res="";
        for(int j=n-1;j>=0;j--)
        {
            if((num[j]-'0')%2!=0)
            {
                return num.substr(0,j+1);
            }
        }
        return res=="0" ? "": res;
    }
};
// time complexity: O(n)
// space complexity:O(1)
