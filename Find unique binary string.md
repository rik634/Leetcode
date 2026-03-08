## problem statement
- Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

### Brute force
```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        unordered_set<string> st(nums.begin(),nums.end());
        queue<string> q;
        q.push("");
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p.length()>n)
            {
                break;
            }
            if(p.length()==n && st.find(p)==st.end())
            {
                return p;
            }
            q.push(p+'0');
            q.push(p+'1');
        }
        return "";

    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(n*n)


### better
```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            int num = stoi(nums[i], 0, 2);
            st.insert(num);
        }
        for (int i = 0; i <= n; i++) {
            if (st.find(i) == st.end()) {
                string res = bitset<16>(i).to_string();
                return res.substr(16 - n);
            }
        }
        return "";
    }
};
```
- Time compelxity: O(n*n) (We iterate over n strings and convert them to integers, costing O(n) for each integer. We then iterate num in the range [0, n]. When we find the answer, we spend O(n) to convert it to a string.)
- space complexity: O(n)

### Optimized (Cantor's diagonal argument)
```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
