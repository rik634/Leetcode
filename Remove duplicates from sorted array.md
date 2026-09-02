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
1. How would this change if each value were allowed to appear at most twice
   - It's a natural extension of the same two-pointer pattern — you just change the comparison rule slightly.
   - The key change in thinking:
     - In the original problem, you compared nums[j] against nums[i] (the last written value) to decide if it's a duplicate. Here, since duplicates up to 2 are allowed, that single-element comparison isn't enough — you need to check against the value two positions back in the write pointer's frame, i.e., nums[i-2], to decide whether adding nums[j] would exceed the "at most twice" limit.
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int i = 2;
        for (int j = 2; j < n; j++) {
            if (nums[j] != nums[i - 1] || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
```
   - Instead of comparing nums[j] to just the last written value, compare it to the value k positions back (here, nums[i-2]) in the compacted prefix — that tells you whether writing nums[j] would exceed the allowed duplicate count. Same O(n) time, O(1) space two-pointer approach, generalizes cleanly to "at most k" by just changing the offset.
   
2. How would you solve this if the array is not sorted?
   - This changes the problem meaningfully. The original two-pointer trick for LeetCode 26 works only because sortedness guarantees duplicates are adjacent — a single forward scan comparing to the immediately preceding element is enough. Without sorting, duplicates can be scattered anywhere in the array, so that trick breaks down entirely.
   - Why the two-pointer approach fails here
     - Consider [4, 1, 4, 2, 1, 3]. The two 4s and two 1s aren't adjacent — comparing each element only to its immediate neighbor (nums[i] vs nums[j]) tells you nothing about whether that value showed up earlier somewhere else in the array. You need a way to remember every distinct value seen so far, not just the last one.
   - Approach 1: Hash Set — O(n) time, O(n) space (most common answer)
     - If order must be preserved (keep first occurrence of each value, in original relative order):
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (seen.find(nums[j]) == seen.end()) {
                seen.insert(nums[j]);
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
```
     
   - This is a two-pointer pattern (slow i, fast j), but now i only advances when nums[j] is a genuinely new value — determined by an O(1) average-case hash set lookup rather than a simple adjacent comparison. It's still a single pass over the array, and it still compacts in-place at the front (positions 0..i-1 hold the deduplicated result), but you've traded the O(1) space of the sorted version for O(n) space to hold the hash set.
   - This is the standard, expected answer for "remove duplicates from an unsorted array while preserving order."
   - Approach 2: Sort first, then apply the classic two-pointer trick — O(n log n) time, O(1) extra space -> If preserving the original relative order is not required:
   - This is a classic time-space trade-off, and calling it out explicitly is usually exactly what the interviewer wants to hear: you can't get both O(n) time and O(1) space and preserved order simultaneously on an unsorted array — you have to sacrifice one of the three. On a sorted array, you get all three for free because sortedness already does the "grouping duplicates together" work at no cost.
   - Without sorting, duplicates aren't adjacent, so the classic O(1)-space two-pointer trick no longer applies — you need something that remembers all values seen so far. The standard fix is a hash set for O(n) time, O(n) space, single pass, preserving order. Alternatively, sort first and reuse the original two-pointer approach for O(n log n) time and O(1) extra space, but that sacrifices the original element order — a genuine three-way trade-off between time, space, and order-preservation that doesn't fully resolve on unsorted input.

3. Can you do this without using the difference check against slow, using count of occurrences instead?
   - Good instinct to ask — this is a genuinely different (and arguably more intuitive) way to express the same logic, and it generalizes more transparently. I'll assume you mean the "at most twice" variant (since that's the one with the nums[i-2] offset trick), and show both that and the general "at most k" version.
   - The core idea
     - Instead of comparing the current element to a value sitting k positions back in the write pointer's frame, you explicitly track a running count of how many times the current value has appeared consecutively (since the array is sorted, "consecutively" = "total," because duplicates are adjacent). You only write the current element if its count-so-far is still within the allowed limit.
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0;       // write pointer
        int count = 1;    // count of current run's occurrences

        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
```
   - How this differs in mechanics
     - count tracks how many times the current run's value has been seen so far (reset to 1 whenever a new value starts).
     - Instead of asking "does this differ from the value 2 slots back in my compacted output?", you directly ask "have I already used up my quota of 2 for this value?"
     - If count <= 2, it's safe to write; otherwise, skip.
   - This is logically equivalent to the offset-comparison trick, but it's more explicit about intent — some people find it easier to reason about and extend, since "count" directly encodes the rule being enforced ("at most k occurrences") rather than relying on the geometric property that in a compacted valid-so-far array, position i-k holds exactly the right comparison value.
   - generalizing to at most K:

```cpp
int removeDuplicates(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;

    int i = 0;
    int count = 1;

    for (int j = 1; j < n; j++) {
        if (nums[j] == nums[j - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count <= k) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```
   - Both are O(n) time and O(1) space — the count-based version doesn't cost you anything asymptotically; it's a stylistic/clarity trade-off, not a performance one.
   - Yes — instead of comparing nums[j] to the value k positions back in the compacted array (which relies on a slightly non-obvious geometric property), you can explicitly track a count of the current run's length as you scan, resetting it whenever the value changes, and only write to the array while count <= k. Same O(n) time, O(1) space, but arguably more directly expresses the "at most k duplicates" rule, and generalizes just as cleanly.

## Pattern connection
- Move Zeroes and Remove Element, which use the exact same slow and fast pointer idea for compacting an array in place.
- Any problem that says remove or compact an already sorted array, where checking only the previous element is enough to detect a duplicate.

## IMP
- Pattern: two pointer, in place compacting of a sorted array.
- Core Idea: slow marks the next free write position, fast scans for the next value different from what slow currently holds.
- Time: O(n) for both the brute force and the optimized version.
- Space: O(n) for the brute force, O(1) for the optimized version.
- Most Important Observation: a sorted array means duplicates are always neighbours, so no extra memory is needed to detect them.
- Interview Difficulty: easy to state, the two pointer in place write is the small detail that separates a working solution from an optimal one.
- One line memory trick: slow writes, fast scans, move slow only when a new value shows up.
