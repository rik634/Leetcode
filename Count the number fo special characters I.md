## Problem statement
- You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
- Return the number of special letters in word.

### Solution
```cpp
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_set<char> st(word.begin(),word.end());
        int count=0;
        for(auto it:st){
            char up = it+32;
            if(st.find(up)!=st.end()){
                count++;
            }
        }
        return count;
    }
};
```
- Time complexity: O(N)
- Space complexity: O(N)
