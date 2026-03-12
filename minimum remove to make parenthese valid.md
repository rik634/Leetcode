## Problem statement
- Given a string s of '(' , ')' and lowercase English characters.
- Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
- Formally, a parentheses string is valid if and only if:
  1. It is the empty string, contains only lowercase characters, or
  2. It can be written as AB (A concatenated with B), where A and B are valid strings, or
  3. It can be written as (A), where A is a valid string.

### Solution (stack)
```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.length();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                continue;
            } else {
                if (st.empty()) {
                    st.push(i);
                } else {
                    char ch = s[st.top()];
                    if (ch == '(' && s[i] == ')') {
                        st.pop();
                    } else {
                        st.push(i);
                    }
                }
            }
        }

        while (!st.empty()) {
            s.erase(st.top(), 1);
            st.pop();
        }
        return s;
    }
};
```
- Time complexity: O(n*n) // sometmes .erase() is slow, which makes O(n*n)
- Space complexity: O(n)

### Better
```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.size() > 0) {
                    st.pop();
                } else {
                    s[i] = '#';
                }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        string str = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '#') {
                str += s[i];
            }
        }
        return str;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### optimized (2 pointer + overwrite)
```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.length();
        int index = 0;
        int balance = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (balance > 0) {
                    balance--;
                    s[index++] = s[i];
                }

            } else {
                if (s[i] == '(') {
                    balance++;
                }
                s[index++] = s[i];
            }
        }
        int len = index;
        index = len - 1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '(' && balance > 0) {
                balance--;
                continue;
            }
            s[index--] = s[i];
        }
        return s.substr(index + 1, len - (index + 1));
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
