## Problem statement



### Solution
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if ((i % 2 == 0 && nums[i] > 0) || (i % 2 != 0 && nums[i] < 0)) {
                continue;
            }
            int j = i + 1;
            while (j < n) {
                if ((i % 2 == 0 && nums[j] > 0) ||
                    (i % 2 != 0 && nums[j] < 0)) {
                    break;
                }
                j++;
            }
            while (j >= 0 && j > i) {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
        return nums;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Better
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }
        int i = 0;
        for (auto it : pos) {
            nums[i] = it;
            i += 2;
        }
        i = 1;
        for (auto it : neg) {
            nums[i] = it;
            i += 2;
        }
        return nums;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### Optimal
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n, 0);
        int pos = 0;
        int neg = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res[pos] = nums[i];
                pos += 2;
            } else {
                res[neg] = nums[i];
                neg += 2;
            }
        }
        return res;
    }
};
```
- Time complexity: O(n)
- Space complexity; O(n)
