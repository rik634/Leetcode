## Problem statement
- A parentheses string is valid if and only if:
  1. It is the empty string,
  2. It can be written as AB (A concatenated with B), where A and B are valid strings, or
  3. It can be written as (A), where A is a valid string.
- You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
- For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
- Return the minimum number of moves required to make s valid.

### Solution
```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {

        if (s.length() == 0) {
            return 0;
        }
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    st.push(s[i]);
                } else {
                    char ch = st.top();
                    if (ch == '(') {
                        st.pop();
                    } else {
                        st.push(s[i]);
                    }
                }
            }
        }
        return st.size();
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n) (stack)
