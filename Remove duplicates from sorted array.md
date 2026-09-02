## Problem statement
- Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
- Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
- The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

### Brute force
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int k = st.size();
        int ind = 0;
        for (auto it : st) {
            nums[ind] = it;
            ind++;
        }
        return k;
    }
};
```
- Time complexity: O(nlogk)
- Space complexity: O(k)

### solution
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        unordered_set<int> st;
        int i=1;
        int j=1;
        st.insert(nums[0]);
        while(j<n){
            if(st.find(nums[j])==st.end()){
                nums[i]=nums[j];
                i++;
                st.insert(nums[j]);
            }
            j++;
        }
        return st.size();
    }
};
```
- Time complexity: O(n)
- Space complexity: O(k)
  
### Better (two pointer)
- Keep a slow pointer starting at index 0. Walk through the array with a fast pointer starting at index 1. Whenever nums at fast is different from nums at slow, move slow one step forward and copy the fast value into that slot.
- The slow pointer only advances when a genuinely new value is found, so it always lands exactly one position past the last unique value written. Because nums is sorted, once we move past a value we will never see it again, so writing over old slots is always safe.
- Mention early that the array being sorted is what allows a simple neighbour check instead of a hash set. This shows the interviewer that the solution is chosen because of the specific constraint given, not just copied from memory.
- If the interviewer asks "what if the array were not sorted", think: a hash set would then be needed to know if a value has been seen before, since duplicates would no longer sit next to each other.
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
```
- Time complexity: O(N)
- Space complexity: O(1)


## Follow-up question
