// level: Easy
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        vector<int> res;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// time complexity: O(n)
// space complexity: O(n)

// space optimzied
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        int n = nums.size()-2;
        int sum = 0, squaredSum = 0;
        for (int x : nums) {
            sum += x;
            squaredSum += x * x;
        }
       int sum2 = sum - (n*(n-1))/2;
        int squaredSum2 = squaredSum - n * (n - 1) * (2 * n - 1) / 6;
         int x1 = (sum2 - sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        int x2 = (sum2 + sqrt(2 * squaredSum2 - sum2 * sum2)) / 2;
        return {x1, x2};
    }
};
// time complexity: O(n)
// space complexity: O(1)
