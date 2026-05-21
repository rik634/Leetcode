## Problem statement
- You are given two arrays with positive integers arr1 and arr2.
- A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
- A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.
- You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
- Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

### Brute force
```cpp
class Solution {
public:
    int longestPrefix(string s1, string s2) {
        int x = s1.length();
        int y = s2.length();
        int a = 0;
        int b = 0;
        while (a < x && b < y) {
            if (s1[a] == s2[b]) {
                a++;
                b++;
            } else {
                return a;
            }
        }
        return a;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mx = max(mx,
                         longestPrefix(to_string(arr1[i]), to_string(arr2[j])));
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*m*k) (k = max digits in a element of array)
- Space complexity: O(d)

### Opyimized
```cpp
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        int mx = 0;
        unordered_set<string> st;
        for (int i = 0; i < n; i++) {
            string s = to_string(arr1[i]);
            string temp = "";
            for (auto it : s) {
                temp += it;
                st.insert(temp);
            }
        }
        for (int i = 0; i < m; i++) {
            string s1 = to_string(arr2[i]);
            string temp = "";
            for (auto it : s1) {
                temp += it;
                if (st.find(temp) != st.end()) {
                    mx = max(mx, (int)temp.length());
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*d*d) + O(m*d*d) (it is d^2, due to extra string operation in inner loop, adn string insert operation in unordered_set)
- Space complexity: O(d8d*max(n,m)) (there are n*d strings, and each string takes max d space)

### space optimized
```cpp
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        int mx = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int temp = arr1[i];
            while(temp>0){
                st.insert(temp);
                temp=temp/10;
            }
        }
        for (int i = 0; i < m; i++) {
            int temp = arr2[i];
            while(temp>0){
                if(st.find(temp)!=st.end()){
                    mx=max(mx,(int)to_string(temp).length());
                }
                temp=temp/10;
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*d+m*d)
- Space complexity: O(n*d)
