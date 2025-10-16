// Level: Medium
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        int n = nums.size();
        vector<int> mp(value,0);
       for(int i=0;i<n;i++)
       {
           int x = (nums[i]%value + value) % value;
           mp[x]++;
       }
       int mx=0;
     
       while(mp[mx%value]>0)
       {
          mp[mx%value]--;
          mx++;
         
       }
       return mx;

    }
};
// time complexity: O(n)
// space complexity: O(1)
