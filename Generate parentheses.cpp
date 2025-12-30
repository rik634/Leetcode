// level: Medium
// problme statwment: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// brute force
class Solution {
public:
    bool isValid(string str)
    {
        int count=0;
        for(auto it:str)
        {
            if(it=='(')
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count<0)
            {
                return false;
            }
        }
        return count==0;
    }
    void getParentheses(int& n, string curr, vector<string>& res)
    {
        if(curr.length()==2*n)
        {
            if(isValid(curr))
            {
                res.push_back(curr);
                
            }
            return ;
        }
        getParentheses(n,curr+'(',res);
        getParentheses(n,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        getParentheses(n,"",res);
        return res;
    }
};
// time complexity: O(n*(2^(2*n))
// space complexity:O(n)

// optimized
class Solution {
public:
   
    void getParentheses(int& n, string curr,int open, int close, vector<string>& res)
    {
        if(curr.length()==2*n)
        {
            res.push_back(curr);
            return ;
        }
        if(open<n)
        {
            getParentheses(n,curr+'(',open+1,close,res);
        }
        if(close<open)
        {
            getParentheses(n,curr+')',open,close+1,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        getParentheses(n,"",0,0,res);
        return res;
    }
};
// time complexity: O(2^(n))
// space complexity:O(n)
