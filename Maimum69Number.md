## Problem statement
- You are given a positive integer num consisting only of digits 6 and 9.
- Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

### Solution
```cpp
class Solution {
public:
    int maximum69Number(int num) {

        string str = to_string(num);
        string s = "";
        bool flag = false;
        for (auto it : str) {
            if (it == '6' && flag == false) {
                s += '9';
                flag = true;
            } else {
                s += it;
            }
        }
        return stoi(s);
    }
};
```
- TC: O(n) (n=length of string)
- SC = O(n)

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        
        string str = to_string(num);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='6')
            {
                str[i]='9';
                break;
            }
        }
        return stoi(str);
    }
};
```
- TC = O(n)
- SC = O(n)
