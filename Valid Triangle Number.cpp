// Level: Medium
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=2;i<n;i++)
        {
            int c = nums[i];
            int l=0;
            int r = i-1;
            while(l<r)
            {
                if((nums[l]+nums[r])>c)
                {
                    count+=(r-l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return count;
    }
};

// time complexity: OO(n^2)
// space complexity: O(1)
