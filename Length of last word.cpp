//Level: Easy
// Splitting a string is the process of dividing the given string into multiple substrings 
//on the basis of a character (or substring) as the separator. 
//This separator is called delimiter and the whole process is also called tokenization.
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len=0;
       stringstream ss(s);
       string t;
       char del=' ';
       while(getline(ss,t,del))
       {
        len = t.length()!=0 ? t.length() : len;
       }
       return len;
    }
};
// Time complexity: O(n)
// space complexity: O(1)
