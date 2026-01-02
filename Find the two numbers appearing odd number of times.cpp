// problem statement: Given an array nums of length n, every integer in the array appears twice except for two integers. 
//Identify and return the two integers that appear only once in the array. Return the two numbers in ascending order.
//For example, if nums = [1, 2, 1, 3, 5, 2], the correct answer is [3, 5], not [5, 3].

// brute force
class Solution {
public:
    /* Function to get the single 
    number in the given array */
    vector<int> singleNumber(vector<int>& nums){    
        vector<int> ans;
        unordered_map <int, int> mpp;
        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++; // Update the map
        }
        for(auto it : mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }  
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// time complexity: O(n) + O(n) + O(2log2) = O(n)
// space complexity: O(n)

// space optimized
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        int n = nums.size();   
        // Variable to store XOR of all elements
        long XOR = 0;
        for(int i=0; i < n; i++) {
            XOR = XOR ^ nums[i];
        }
        /* Variable to get the rightmost 
        set bit in overall XOR */
        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        /* Variables to stores XOR of
        elements in bucket 1 and 2 */
        int XOR1 = 0, XOR2 = 0;
        // Traverse the array
        for(int i=0; i < n; i++) {
            /* Divide the numbers among bucket 1
             and 2 based on rightmost set bit */
            if(nums[i] & rightmost) {
                XOR1 = XOR1 ^ nums[i];
            }
            else {
                XOR2 = XOR2 ^ nums[i];
            }
        }     // Return the result in sorted order
        if(XOR1 < XOR2) return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};
// time complexity: O(n)
// space complexity: O(1)
