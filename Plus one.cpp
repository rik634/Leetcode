// level: easy
// problem statement: 

// brute force
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        stack<int> st;
        int carry=1;
        int n = digits.size();
        vector<int> res;
        for(int i=n-1;i>=0;i--)
        {
            st.push((carry+digits[i])%10);
            carry = (carry+digits[i])/10;
        }
        if(carry)
        {
            st.push(carry);
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
// time complexity: O(n) + O(n) = O(n)
// space complexity:O(n)

// space optimized
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
       
        int carry=1;
        int n = digits.size();
        for(int i=n-1;i>=0;i--)
        {
            int sum = carry+digits[i];
            digits[i]=(sum)%10;
            carry = (sum)/10;
        }
        if(carry)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
        
    }
};
// time complexity:O(n)
// space complexity:O(1)
