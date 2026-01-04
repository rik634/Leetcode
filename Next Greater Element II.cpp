// level: Medium
// problem statement: Given a circular integer array arr, return the next greater element for every element in arr.
//The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner.
//If it doesn't exist, return -1 for that element element.


// brute force:
class Solution {
public:

    /* Function to find the next greater element
    for each element in the circular array */
    vector<int> nextGreaterElements(vector<int> arr) {
       
        int n = arr.size(); // size of array
        
        // To store the next greater elements
        vector<int> ans(n, -1);
        
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
             
            /* Nested loop to get the 
            next greater element */
            for(int j=1; j < n; j++) {
                
                // Getting the hypothetical index
                int ind = (j+i) % n;
                
                // If the next greater element is found
                if(arr[ind] > currEle) {
                    
                    // Store the next greater element
                    ans[i] = arr[ind];
                    
                    // Break from the loop
                    break;
                }    
            }
        }
       
        // Return the answer
        return ans;
    }
};

//Time Complexity: O(N2), since we are using two nested for loops to find the next greater elements.
//Space Complexity: O(N), The space required to store the answer is O(N).

// optimized:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
//Time Complexity: O(N), since traversing on the array takes O(N) time and traversing the stack will take overall O(N) time as all the elements are pushed in the stack once.
//Space Complexity: O(N), since the answer array takes O(N) space and the space used by stack will be O(N) in the worst case.

// another optimized

class Solution {
public:

    /* Function to find the next greater 
    element for each element in the array */
    vector<int> nextGreaterElements(vector<int> arr) {
        
        int n = arr.size(); //size of array
        
        // To store the next greater elements
        vector<int> ans(n);
        
        // Stack to get elements in LIF fashion
        stack<int> st;
        
        // Start traversing from the back
        for(int i = 2*n-1; i >= 0; i--) {
            
            // Get the actual index
            int ind = i % n;
            
            // Get the current element
            int currEle = arr[ind];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            // Store the answer for the second half
            if(i < n) {
                
                /* If the greater element is not 
                found, stack will be empty */
                if(st.empty()) 
                    ans[i] = -1;
                    
                // Else store the answer
                else 
                    ans[i] = st.top();
            }
            
            /* Push the current element in the stack 
            maintaining the decreasing order */
            st.push(currEle);
        }
        
        // Return the result
        return ans;
    }
};
//Time Complexity: O(N), since traversing on the array takes O(N) time and traversing the stack will take overall O(N) time as all the elements are pushed in the stack once.
//Space Complexity: O(N), since the answer array takes O(N) space and the space used by stack will be O(N) in the worst case.
