// Level: Medium
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size();
        int ans=0;
        unordered_map<int,int> even;
        unordered_map<int,int> odd;
        for(int i=0;i<n;i++)
        {
            even.clear();
            odd.clear();
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2==0)
                {
                    even[nums[j]]++;
                }
                else
                {
                    odd[nums[j]]++;
                }
                if(even.size()==odd.size())
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};

//Time Complexity: O(n^2)
//space complexity: O(n)
