// level: easy
// weekly contest 476
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {

        priority_queue<int> pq;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            mn=min(mn,nums[i]);
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        return a+b-mn;
    }
};

// Time complexity: O(n * logn) + O(log2)
// space complexity: O(n)
