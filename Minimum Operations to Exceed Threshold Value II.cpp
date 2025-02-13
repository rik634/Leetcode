//level: meidum
//link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/?envType=daily-question&envId=2025-02-13
//solution

class Solution {
public:
    long long M=1000000009;
    int minOperations(vector<int>& nums, int k) {
        
        long long n = nums.size();
        priority_queue<long long ,vector<long long>,greater<long long>> q(nums.begin(),nums.end());//min heap
        long long count=0;
        while(q.size()>=2 && q.top()<k)
        {
            count++;
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            q.push(((min(x,y)*2)+max(x,y)));
        }
        return count;
    }
};
