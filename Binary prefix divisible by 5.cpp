// Level: easy
// here, we have used the horner's method logic
class Solution {
public:
    long long MOD=1e9+7;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> answer(n,false);
        long long decimal=0;
        for(int i=0;i<n;i++)
        {
            decimal = ((decimal*2) + nums[i])%5;
            if(decimal==0)
            {
                answer[i]=true;
            }
        }
        return answer;
    }
};
// Time complexity: O(n)
// space complexity: O(n)
