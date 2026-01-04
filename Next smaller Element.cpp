// problem statement: Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
//The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
//If there is no smaller element to the right, then the NSE is -1.

// brute force

class Solution {
public:

    /* Function to find the next smaller 
    element for each element in the array */
    vector<int> nextSmallerElement(vector<int>& arr) {
        
        int n = arr.size(); // size of array
        
        // To store the next smaller elements
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; ++i) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Nested loop to get the 
            next smaller element */
            for (int j = i + 1; j < n; ++j) {
                
                // If the next smaller element is found
                if (arr[j] < currEle) {
                    
                    // Store the next smaller element
                    ans[i] = arr[j];
                    
                    // Break from the loop
                    break;
                }
            }
        }
        
        // Return the answer
        return ans;
    }
};
// time complexity: O(n*n)
// space complexity: O(n)

// optimzied
class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();

        // Stack to store potential next smaller elements
        stack<int> st;

        // Answer array initialized with -1
        vector<int> ans(n, -1);

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop elements from stack while they are >= current element
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // If stack is not empty, top is the next smaller element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current element to stack
            st.push(arr[i]);
        }

        // Return result
        return ans;
    }
};

// time complexity: O(N), since each element is pushed and popped at most once.
// space complexity: O(N), since stack may hold up to N elements in the worst case.
