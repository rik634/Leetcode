## Problem statement
- Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

### Brute force
```cpp
class Solution {
public:
    bool checkNumber(vector<int>& nums, int num) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int count = 1;
            while (checkNumber(nums, x + 1) == true) {
                x++;
                count++;
            }
            mx = max(mx, count);
        }
        return mx;
    }
};
```
- Time complexity: O(n*n*n)
- Space complexity; O(1)

### Better
```cpp
class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        unordered_set<int> st;
        for(auto it:nums)
        {
            st.insert(it);
        }
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int count = 1;
            while (st.find(x+1)!=st.end()) {
                x++;
                count++;
            }
            mx = max(mx, count);
        }
        return mx;
    }
};
```
- Time complexity: O(n) + O(n*n)
- Space complexity: O(n)

### Better
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int mx = 1;
        sort(nums.begin(), nums.end());

        int count = 0;
        int last = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] - 1 == last) {
                count++;
            } else if (nums[i] != last) {
                count = 1;
            }
            last = nums[i];
            
            mx = max(mx, count);
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

