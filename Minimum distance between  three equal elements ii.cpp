// level: Medium
class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int mn=INT_MAX;
        for(auto it: mp){
            int num = it.first;
            vector<int> v = it.second;
            if(v.size()<3)
            {
                continue;
            }
            
            for(int j=0;j<v.size()-2;j++){
                mn=min(mn,2*(v[j+2]-v[j]));
            }
        }
        return mn==INT_MAX ? -1 : mn;
    }
};

// Time complexity: O(n)
// space complexity: O(n)
