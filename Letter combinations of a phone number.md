## problem statement:
- Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter combinations that the number can represent.

### solution (DFS):
```cpp
class Solution {
public:
    void findCombination(int ind, string curr, string& digits, unordered_map<int,string>& mp,vector<string>& res)
    {
        if(ind==digits.size())
        {
            res.push_back(curr);
        }

        for(char ch: mp[digits[ind]-'0'])
        {
            findCombination(ind+1,curr+ch, digits,mp,res);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int,string> mp={
            {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        };
        vector<string> res;
        string curr="";
        findCombination(0,curr,digits,mp,res);
        return res;

    }
};
```
- time complexity: (n*(4^n))
-  space complexity: O(n) (recursive stack space) + O(n*(4^n))

### Solution (BFS)
```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        int n = digits.length();
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        string curr = "";
        queue<pair<int, string>> q;
        q.push({0, curr});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int ind = p.first;
            string str = p.second;
            int org = str.length();
            if (ind == n) {
                res.push_back(str);
                continue;
            }
            for (auto it : mp[digits[ind]]) {
                str += it;
                q.push({ind + 1, str});
                str.resize(org);
            }
        }
        return res;
    }
};
```
- Time complexity: O(n*(4^n))
- Space complexity: O(4^n) (at one level, the queue can have max 4^n strings)
