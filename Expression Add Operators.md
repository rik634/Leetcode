## Problem statement
- Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
- Note that operands in the returned expressions should not contain leading zeros.
- Note that a number can contain multiple digits.

### Logic:
### Solution
```cpp
class Solution {
public:
    void findString(int ind, string& num, int& target, long long currVal,
                    string curr, long long prevOp, vector<string>& res) {
        if (ind == num.length()) {
            if (currVal == target) {
                res.push_back(curr);
            }
            return;
        }

        for (int i = ind; i < num.length(); i++) {
            if (i > ind && num[ind] == '0') {
                break;
            }
            string p = num.substr(ind, i - ind + 1);
            long long val = stol(p);
            if (ind == 0) {
                findString(i + 1, num, target, val, p, val, res);
            } else {
                // addition
                findString(i + 1, num, target, currVal + val, curr + '+' + p,
                           val, res);
                // substraction
                findString(i + 1, num, target, currVal - val, curr + '-' + p,
                           (-1) * val, res);

                // multiplication
                findString(i + 1, num, target,
                           (currVal - prevOp) + (prevOp * val), curr + "*" + p,
                           prevOp * val, res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {

        int n = num.length();
        if (n == 0) {
            return {};
        }
        vector<string> res;
        findString(0, num, target, 0, "", 0, res);
        return res;
    }
};
```
- Time complexity: O(n*(4^n)) (O(N * 4^N) 4 choices per digit gap, multiplied by string copy time.)
- Space complexity: O(n*n) (stack space*string length)

### Better
- Here, in order to reduce the time complexity, we are passing the temporary string as reference to the function. This will reduce the stirng copying time. 
```cpp
class Solution {
public:
    void findString(int ind, string& num, int& target, long long currVal,
                    string& curr, long long prevOp, vector<string>& res) {
        if (ind == num.length()) {
            if (currVal == target) {
                res.push_back(curr);
            }
            return;
        }
        int org = curr.length();
        for (int i = ind; i < num.length(); i++) {
            if (i > ind && num[ind] == '0') {
                break;
            }
            string p = num.substr(ind, i - ind + 1);
            long long val = stol(p);
            if (ind == 0) {
                curr += p;
                findString(i + 1, num, target, val, curr, val, res);
                curr.resize(org);
            } else {
                // addition
                curr += '+' + p;
                findString(i + 1, num, target, currVal + val, curr, val, res);
                curr.resize(org);
                // substraction
                curr += '-' + p;
                findString(i + 1, num, target, currVal - val, curr, (-1) * val,
                           res);
                curr.resize(org);

                // multiplication
                curr += "*" + p;
                findString(i + 1, num, target,
                           (currVal - prevOp) + (prevOp * val), curr,
                           prevOp * val, res);
                curr.resize(org);
            }
        }
    }
    vector<string> addOperators(string num, int target) {

        int n = num.length();
        if (n == 0) {
            return {};
        }
        vector<string> res;
        string curr = "";
        findString(0, num, target, 0, curr, 0, res);
        return res;
    }
};
```
- Time complexity: O(4^n)
- Space complexity: O(n)
