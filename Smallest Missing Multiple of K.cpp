// Level: Easy
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();
        int i=1;
        while(s.find(k*i)!=s.end())
        {
            i++;
        }
        return k*i;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
