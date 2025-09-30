// leveL: Medium
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int count=0;
        vector<int> temp=nums;
        while(count<n-1)
        {
            for(int i=0;i<temp.size()-1;i++)
            {
                temp[i]=(temp[i]+temp[i+1])%10;
            }
            temp.pop_back();
            count++;
        }
        return temp[0];
    }
};
// time complexity: O(n*n)
// space complexity: O(n)
