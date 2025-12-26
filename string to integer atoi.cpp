// level:Medium
// problem statement:  Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
//1. Whitespace: Ignore any leading whitespace (" ").
//2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
//3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
//4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

//Return the integer as the final result.

// brute force
class Solution {
public:
    int myAtoi(string s) {

        int n = s.length();
        int flag = 1; // string is a positive integer
        int i = 0;
        long num = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }
        if (s[i] == '-') {
            flag = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        while (isdigit(s[i]) && i < n) {
            num = num * 10 + (int)(s[i] - '0');
            if (flag * num > INT_MAX) {
                return INT_MAX;
            }
            if (flag * num < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return (int)(flag * num);
    }
};
// time complexity:O(n)
//space complexity: O(1)
