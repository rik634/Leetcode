## Problem statement
- Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters.
- If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

### Brute force (recursive)
```cpp
class Solution {
public:
    void generate(int ind, string curr, string& s, vector<string>& v) {
        if (ind == s.length()) {
            v.push_back(curr);
            return;
        }
        int org = curr.length();
       
        generate(ind + 1, curr+s[ind], s, v);
        curr.resize(org);
        generate(ind + 1, curr, s, v);
    }
    string findLongestWord(string s, vector<string>& dictionary) {

        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<string> v;
        string curr = "";
        generate(0, curr, s, v);
        string str = "";
        for (int i = 0; i < v.size(); i++) {
            if (st.find(v[i]) != st.end()) {
                if (v[i].length() > str.length() ||
                    (v[i].length() == str.length() && v[i].compare(str)<0)) {
                    str = v[i];
                }
            }
        }
        return str;
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(2^n)

### Brute force (iterative)
```cpp
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<string> v;
        for (int i = 0; i < (1 << n); i++) {
            string curr = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curr += s[j];
                }
            }
            v.push_back(curr);
        }
        string str = "";
        for (int i = 0; i < v.size(); i++) {
            if (st.find(v[i]) != st.end()) {
                if (v[i].length() > str.length() ||
                    (v[i].length() == str.length() && v[i].compare(str) < 0)) {
                    str = v[i];
                }
            }
        }
        return str;
    }
};
```
- Time complexity: O(2^n)
- Space complexity: O(2^n)

### Solution
```cpp
class Solution {
public:
    static bool myComp(const string& a, const string& b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() > b.length();
    }
    bool findLCS(string& a, string& b) {
        int l = a.length();
        int m = b.length();
        int i = 0;
        int j = 0;
        while (i < l && j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i != l) {
            return false;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {

        int n = dictionary.size();
        sort(dictionary.begin(), dictionary.end(), myComp);
        for (int i = 0; i < n; i++) {
            if (findLCS(dictionary[i], s)) {
                return dictionary[i];
            }
        }
        return "";
    }
};
```
- Time complexity: O(n*klogn) (o arrange words by length and lexicographical order., k = average length of words in dictionary) + O(n*L) (L= length of parent string)
- Space complexity: O(1)

### Optimizes (without sorting)
```cpp
class Solution {
public:
    bool checkIfEq(string x, string y) {
        int l = x.length();
        int r = y.length();
        int i = 0;
        int j = 0;
        while (i < l && j < r) {
            if (x[i] == y[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == l;
    }
    string findLongestWord(string s, vector<string>& dictionary) {

        string str = "";
        for (auto ss : dictionary) {
            if (checkIfEq(ss, s)) {
                if (ss.length() > str.length() ||
                    (ss.length() == str.length() && ss.compare(str) < 0)) {
                    str = ss;
                }
            }
        }
        return str;
    }
};
```
- Time complexity: O(n*x) (One iteration over all strings is required. Here n refers to the number of strings in list d and x refers to average string length.)
- Space complexity: O(x) (str variable is used.)
