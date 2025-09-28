// Level: Easy
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mx=0;
        for(int i=0;i<n-2;i++)
        {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(c<(a+b))
            {
                mx=max(mx,a+b+c);
            }
        }
        return mx;
    }
};
// time complexity: O(nlogn) + O(n)
// space complexity: O(1)
