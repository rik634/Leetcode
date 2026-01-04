// level: Easy
// problem statement: Given an integer array A, return the next greater element for every element in A. 
//The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

// brute force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            int ind=-1;
            int nextGreater=-1;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums2[j]==nums1[i])
                {
                    ind=j;
                }
                if(ind!=-1 && nextGreater==-1&& nums2[j]>nums1[i])
                {
                    nextGreater=nums2[j];
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(nextGreater==-1)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
// time complexity: O(n*m) (n=size of nums1, m=size of nums2)
// space complexity: O(n)

// a bit optimized
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]=i;
        }
        for(int i=0;i<nums1.size();i++)
        {
            int ind=-1;
            int nextGreater=-1;
            for(int j=mp[nums1[i]];j<nums2.size();j++)
            {
                if(nums2[j]==nums1[i])
                {
                    ind=j;
                }
                if(ind!=-1 && nextGreater==-1&& nums2[j]>nums1[i])
                {
                    nextGreater=nums2[j];
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if(nextGreater==-1)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
// time complexity: <O(n*m)
// space complexity: o(n+m)

// optimized
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        unordered_map<int,int> mp;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]]=-1;
            } else {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};
// time complexity: O(n+m)
// space complexity: O(n+m)
