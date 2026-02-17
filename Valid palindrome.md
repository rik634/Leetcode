## Problem statemnt
- A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
- it reads the same forward and backward. Alphanumeric characters include letters and numbers.
- Given a string s, return true if it is a palindrome, or false otherwise.

 


### Solution
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};
```
- Time complexity: O(n)
- Space complexity: O(1)
