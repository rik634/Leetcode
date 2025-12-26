// level: Medium
// problem statement: Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. 
//The words in s are separated by at least one space. Return a string with the words in reverse order, concatenated by a single space.

// brute force:
class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int n = s.length();
        string temp="";
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(temp.length()!=0)
                {
                    v.push_back(temp);
                    temp="";
                }
                
                continue;
            }
            else
            {
                temp+=s[i];
            }
        }
        if(temp.length()!=0)
        {
            v.push_back(temp);
        }
        reverse(v.begin(),v.end());
        for(auto it:v)
        {
            res+= it;
            res+=" ";
        }
        res.pop_back();
        return res;
    }
};
// time complexity: O(n)+ O(n) (reverseing the vector) = O(n)
// space complexity: O(n)

// optimized (two pointers)
class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        string res="";
        int i = n-1;
        while(i>=0)
        {
            // skip the space at end
            while(i>=0 && s[i]==' ')
            {
                i--;
            }
            if(i<0)
            {
                break;
            }
            int last=i;
            while(i>=0 && s[i]!=' ')
            {
                i--;
            }
            int first=i+1;
            string word = s.substr(first,last-first+1);
            if(!res.empty())
            {
                res+=" ";
            }
            res+=word;
        }
        return res;
    }
};
// time complexity:O(N)
// space complexity:O(1)
