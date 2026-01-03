// Level: easy
// problem statement: Check Balanced Parentheses. Given string str containing just the characters '(', ')', '{', '}', '[' and ']', check if the input string is valid and return true if the string is balanced otherwise return false. .
//Note:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.

// solution:
class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(auto it:s)
        {
            if(it=='(' || it=='{' || it=='[')
            {
                st.push(it);
            }
            else
            {
                if(st.size()==0)
                {
                    return false;
                }
                char ch = st.top();
                if((ch=='(' && it==')') || (ch=='[' && it==']') || (ch=='{' && it=='}'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.size()==0;
    }
};

// time complexity: O(n)
// space complexity: O(n)
