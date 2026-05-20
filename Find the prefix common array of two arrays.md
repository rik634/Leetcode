## Problem statement
- You are given two 0-indexed integer permutations A and B of length n.
- A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
- Return the prefix common array of A and B.
- A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

### Solution
```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            st.insert(B[i]);
            ans.push_back(2*(i+1)-st.size());
        }
        return ans;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)

### optimized
```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();
        vector<int> ans(n);
        int c = 0;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;

            if (freq[A[i]] == 2) {
                c++;
            }
            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                c++;
            }
            ans[i] = c;
        }
        return ans;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(n)
