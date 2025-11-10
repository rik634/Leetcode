// Level: Medium
// use of monotonic stack

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        vector<int> v;
        int count=0;
        for(auto it: nums)
        {
            while(!v.empty() && v.back()>it)
            {
                v.pop_back();
            }
            if(it==0)
            {
                continue;
            }
            if(v.empty() || v.back()<it)
            {
                count++;
                v.push_back(it);
            }
        }
        return count;
    }
};
// time complexity: O(n)
// space complexity: O(n)
