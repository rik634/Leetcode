// Level: Medium
class Solution {
public:
    const int MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        
        int n = nums.size();
        int count=0;
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++)
       {
           mp[nums[i]]++;
       }
       unordered_map<int,int> curr;
       
       for(int j=0;j<n;j++)
       {
          int m = nums[j];
          int prev = curr[2*m];
          curr[nums[j]]++;
          int after = mp[2*m]-curr[2*m];
          count = (count + ((long long)prev*after)%MOD)%MOD;
        
       }
       return count;

    }
};
// Time complexity: O(n)
// Space complexity: O(2*n)
