// level: easy
// problem statement: A valid parentheses string is defined by the following rules:
//It is the empty string "".
//If A is a valid parentheses string, then so is "(" + A + ")".
//If A and B are valid parentheses strings, then A + B is also valid.
//A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.
// Given a valid parentheses string s, your task is to remove the outermost parentheses from every primitive component of s and return the resulting string.

// stack
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int n = s.length();
        stack<char> st;
        vector<string> v;
        string temp="";
        for(int i=0;i<n;i++)
        {
            temp+=s[i];
            if(s[i]=='(')
            {
                st.push('(');
            }
            else
            {
                st.pop();
            }
            if(st.size()==0)
            {
                v.push_back(temp);
                temp="";
            }
        }
        string res="";
        for(int i=0;i<v.size();i++)
        {
            string str = v[i].substr(1,v[i].length()-2);
            res+=str;
        }
        return res;
    }
};

// time complexity : O(n) + O(m=number of primitive valid strings) + O(k=length of string being abstracted)
// space complexity: O(n) + O(m)

// optimized
class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int n = s.length();
        int level=0;
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(level>0)
                {
                    res+=s[i];
                }
                level++;
            }
            else
            {
                level--;
                if(level>0)
                {
                    res+=s[i];
                }
            }
        }
        return res;
    }
};
// time complexity: O(N)
// space complexity:O(1)
