## Problem statement
- You are given an integer array nums.
- A position i is called a fixed point if nums[i] == i.
- You are allowed to delete any number of elements (including zero) from the array. After each deletion, the remaining elements shift left, and indices are reassigned starting from 0.
- Return an integer denoting the maximum number of fixed points that can be achieved after performing any number of deletions.

### Solution
```cpp
class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {

        int n = nums.size();
        vector<pair<int,int>> res;
        for(int i=0;i<n;i++){
            if(i>=nums[i]){
                res.push_back({nums[i],i-nums[i]});
            }
        }
        sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        vector<int> lis;
        for(int i=0;i<res.size();i++){
            auto it = upper_bound(lis.begin(),lis.end(),res[i].second);
            if(it==lis.end()){
                lis.push_back(res[i].second);
            }
            else
            {
                *it = res[i].second;
            }
        }
        return lis.size();
    }
};
```

- Time complexity: O(nlogn)
- Space complexity: O(n)
