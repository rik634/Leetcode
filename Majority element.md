## Problem statement
- Given an array nums of size n, return the majority element.
- The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

### solution:
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        for (auto it : mp) {
            if (it.second > floor(n / 2)) {
                return it.first;
            }
        }
        return 0;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### solution:
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};
```
- Time complexity: O(nlogn)
- Space complexity: O(1)

### Solution (Boyer-moore voting algorithm)
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        int count=0;
        int candidate=0;
        for(auto it:nums){
            if(count==0){
                candidate=it;
            }
            else if(candidate==it){
                count++;
            }
            else if(candidate!=it){
                count--;
            }
        }
        return candidate;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
